#include "readerid3v2tag.h"

ReaderID3V2Tag::ReaderID3V2Tag(QString pathToFile) : ReaderTag(pathToFile)
{
    indexLenght = 6;
    freq = 0;
    file = new QFile(pathToFile);
    if(!file->open(QIODevice::ReadOnly))
        qDebug() << "error open file";
}

ReaderID3V2Tag::~ReaderID3V2Tag()
{
    if(file->isOpen())
        file->close();
    delete file;
}
/**
 * @brief ReaderID3V2Tag::getTag
 * функция нахождения тегов ID3V2 в файле.
 * первыми находятся теги, расположение после заголовка ID3V2.
 * после нахождения этих тегов, производится разбор mp3 фрейма для определения
 * формата, длины, частоты дискретизации и битрейта песни.
 * Нахождение данных в mp3 фрейма должны строго соответствовать заданному порядку:
 * 1. вычисление метоположения заголовка mp3-фрейма = длинна ID3V2 заголовка + длина тегов
 * 2. нахождение версии MPEG
 * 3. нахождение версии Layer
 * 4. нахождение битрейта (зависит от версий MPEG и Layer)
 * 5. нахождение частоты дискретизации ( зависит от версии MPEG)
 * 6. определение ржима канала
 * 7. определение режима сжатия данных (определяется тип заголовка,
 *    после чего по таблице находится смещение относительно первого бита заголовка mp3 фрейма)
 * 8. нахождение длины песни
 * @return
 */
TagInfo ReaderID3V2Tag::getTag()
{
    //qDebug() << "Read ID3V2 tag";
    TagInfo tagInfo;
    int offset = indexLenght;
    if(file->seek(offset))
    {
        tagInfo.pathToFile = getPathToFile();
        int lenght = 4;
        tagInfo.size = file->size();
        QByteArray *array;
        array = readBytesFromFile(indexLenght, lenght + indexLenght);
        int sizeLenghtTags = getLenghtTags(&array->toHex());
        //qDebug() << sizeLenghtTags;
        array->clear();
        array = readBytesFromFile(lenght + indexLenght, sizeLenghtTags);
        tagInfo.album = getInfo("TALB", array);
        tagInfo.title = getInfo("TIT2", array);
        tagInfo.genre = getInfo("TCON", array);
        tagInfo.year = getInfo("TYER", array).toInt();
        tagInfo.trackNum = getInfo("TRCK", array);
        tagInfo.artist = getInfo("TPE1", array);
        array->clear();
        array = readBytesFromFile(sizeLenghtTags + 10, sizeLenghtTags + 10 + 4);
        tagInfo.trackType = getTypeTrack(array);
        tagInfo.beatRate = getBeatRate(array);
        freq = getFrequency(array);
        tagInfo.frequency = freq;
        tagInfo.channel = getChannel(array);
        int offset = getOffset();
        array->clear();
        int vbrHeaderIndex = 10 + sizeLenghtTags + offset; // индекс начала заголовка VBR
        array = readBytesFromFile( vbrHeaderIndex, vbrHeaderIndex + 4 );
        if(array->toLower().contains("xing") || array->toLower().contains("info")) //проверяем тип заголока Xing
        {
            /*
             * Если тип заголовка Xing, то значение количества фреймов находится со смещение 8 от НАЧАЛА ЗАГОЛОВКА
             * длина значения равна 4 байта
             */
            array->clear();
            int indexNumberOfFrame = vbrHeaderIndex + 8;
            array = readBytesFromFile(indexNumberOfFrame, indexNumberOfFrame + 4);
            tagInfo.length = getLenghtTrackVBR(array);
        }
        else
        {   /* если заголовок не равен Xing то проверяем заголовок VBRI. Т.к. он всегда смещен на 32,
             * то необходимо вернкться к индексу заголовка фрейма и прочитать данные со смещением 32
             */
            array->clear();
            int vbrIHeaderIndex = vbrHeaderIndex - offset + 32;
            array = readBytesFromFile(vbrIHeaderIndex, vbrIHeaderIndex + 4);
            if(array->toLower().contains("vbri"))
            {
                /*
                 * Если тип заголовка VBRI, то значение находися со смещением 14 от НАЧАЛА ЗАГОЛОВКА
                 * длинна значения 4 байта
                 */
                array->clear();
                array = readBytesFromFile(vbrIHeaderIndex + 14, vbrIHeaderIndex + 14 + 4);
                tagInfo.length = getLenghtTrackVBR(array);
            }
            else
            {
                /*
                 * если VBR заголовка не существует, то данные сжаты с использованием режима CBR
                 * для посчета длинны песни необходимо знать присутствует ли тег ID3V1 и общее количество битов
                 */
                array->clear();
                int fileSize = file->size();
                array = readBytesFromFile(fileSize - 129, fileSize - 126);
                bool id3v1tag = false;
                if(array->contains("TAG"))
                    id3v1tag = true;
                tagInfo.length = getLenghtTrackCBR(sizeLenghtTags + 10, tagInfo.beatRate, id3v1tag);
            }
        }
    }
    return tagInfo;
}

/**
 * @brief ReaderID3V2Tag::getLenghtTags
 * находит в файле длинну заголовка (участка с тегами)
 * @param data - входные данные
 * @return
 * для понимания алгоритма необходимо значть структуру тега IDv3
 * Длинна заголовка находится в 6 - 9 байтах включительно
 * Для получения длинны извлекаются данные из этих байтов и переводятся в двоичнуюю с.с.
 * каждый 8 бит переведенных значений отбрасывается, после чего оставшиеся биты соединяются между собой
 * получившееся значение есть длинна заголовка
 */
int ReaderID3V2Tag::getLenghtTags(QByteArray *data)
{
    int result = -1;
    QByteArray stringResult;
    for(int i = 0; i < data->size(); i=i+2)
    {
        QByteArray arr = data->mid(i,2);
        if(arr.contains("00"))
            continue;
        QString tmpStr = QString::number(arr.toInt(0, 16), 2);
        if(tmpStr.size() >=7)
            stringResult.append(tmpStr.right(7));
        else
        {
            int k = 7 - tmpStr.size();
            for(int i = 0; i < k; i ++)
            {
                tmpStr.insert(0, "0");
            }
            stringResult.append(tmpStr);
        }
    }
    //qDebug() << stringResult;
    result = stringResult.toInt(0,2);
    //qDebug() << result;
    return result;
}

/**
 * @brief ReaderID3V2Tag::readBytesFromFile
 * считывает байты из файла
 * @param beginIndex - индекс начала
 * @param endIndex - индекс конца
 * @return
 */
QByteArray *ReaderID3V2Tag::readBytesFromFile(int beginIndex, int endIndex)
{
    int lenght = endIndex - beginIndex;
    QByteArray *array = new QByteArray();
    array->resize(lenght);
    if(file->seek(beginIndex))
    {
        file->read(array->data(), lenght);
    }
    return array;
}

/**
 * @brief ReaderID3V2Tag::getInfo
 * возвращает значение заданного тега
 * @param tag - название тега для поиска
 * @param data - данные, содержащие информацию о тегах
 * @return значение заданного тега
 * Для понимания работа данной функции необходимо значть формат тегов ID3V2
 * Ознакомиться можно по ссылке http://id3.org/id3v2.3.0#ID3v2_overview
 * Функция получает название тега, после чего ищет его в массиве данных.
 * Если такой тег присутствует, то определяется его индекс в массиве данных.
 * Размер тега находится в 4 байтах после названия тега, после размера идут 2 байта флагов,
 * следовательно информация для тега находится со смещением <4 байта - ид тега> + < 4 байта - значение размера тега> + <2 байта - флаг>
 * Общий размер тега равен 10 байт + размер данных в теге.
 * при выборке данных используется функция QByteArray::mid. При вычислении индекса начала и длинны происходит корректировка на 1.
 * Это сделанно из-за того, что первым символом является '00'.
 * Для получения окончательного результата производится перебор каждого символа в массиве,
 * для того чтобы убрать символы, которые не отображаются на экране
 */
QString ReaderID3V2Tag::getInfo(QString tag, QByteArray *data)
{

    int index = data->indexOf(tag);
    if (-1 == index)
    {
        qDebug() << tag << " not found";
        return QString();
    }
    QByteArray tagsData = data->mid(index + tag.size(), 4);
    if(tagsData.isEmpty())
    {
        qDebug() << "Error while parse " << tag;
        return QString();
    }
    int sizeTag = tagsData.toHex().toInt(0, 16);
    tagsData.clear();
    tagsData = data->mid(index + 10 + 1, sizeTag - 1 );
    if(tagsData.isEmpty())
    {
        qDebug() << "Error while parse " << tag;
        return QString();
    }
    QString result;
    for(int i = 0; i < tagsData.length(); i++)
    {
        QChar symbol(tagsData.at(i));
        if( (symbol.unicode() >=32 && symbol.unicode() <= 126)
                || (symbol.unicode() >= 1040 && symbol.unicode() <=1163))
            result.append(symbol);
    }
    result.append("\0");
    //QString result = tagsData;
    qDebug() << result ;
    return result;
}

/**
 * @brief ReaderID3V2Tag::getOtherInformation
 * получает информацию о типе трека.
 * также определяет версию MPEG И версию Layer
 * индекс версии MPEG находится в 11-12 битах
 * индекс версии Layer находится в 13-14 битах
 * @param data - заголовок фрейма, содержащий 4 байта
 * @return
 */
QString ReaderID3V2Tag::getTypeTrack(QByteArray *data)
{
    if (data->isEmpty())
    {
        qDebug() << "error while reading frame";
        return QString();
    }

    QString binaryNumber = QString::number(data->toHex().toLongLong(0, 16), 2);
    QString tmpStr = binaryNumber.left(11);
    if(tmpStr.contains("0"))
    {
        qDebug() << "Error reading frame, incorrect marker.";
        return QString();
    }
    tmpStr.clear();
    tmpStr = binaryNumber.mid(11, 2);
    switch (tmpStr.toInt()) {
    case 00:
        type = MPEG_2_5;
        break;
    case 01:
        qDebug() << "этот тип не используется";
        break;
    case 10:
        type = MPEG_2;
        break;
    case 11:
        type = MPEG_1;
        break;
    default:
        qDebug() << "Error while detect type track";
        return QString();
    }

    tmpStr.clear();
    tmpStr = binaryNumber.mid(13, 2);
    switch (tmpStr.toInt()) {
    case 01:
        layer = LAYER3;
        break;
    case 10:
        layer = LAYER2;
        break;
    case 11:
        layer = LAYER3;
        break;
    default:
        qDebug() << "Error while detect layer track";
        return QString();
    }
    QString tmp;

    if(type == MPEG_1 && layer == LAYER3)
    {
        qDebug() << "track type is mp3";
        tmp = "mp3";
    }
    return QString("mp3");
}
/**
 * @brief ReaderID3V2Tag::getBeatRate
 * возвращает значение битрейта.
 * индекс битрейта находится в 16-19 битах,
 * после определения индекса определяется значение по таблице BitRate value http://id3.org/mp3Frame
 * @param data
 * @return
 */
int ReaderID3V2Tag::getBeatRate(QByteArray *data)
{
    int bitrate = 0;
    QString binaryStr = QString::number(data->toHex().toLongLong(0,16), 2);
    QString tmpStr = binaryStr.mid(16, 4);
    if(tmpStr.isEmpty())
    {
        qDebug() << "Error beat rate value";
        return bitrate;
    }
    switch (tmpStr.toInt()) {
    case 0001:
        if(type == MPEG_1)
            bitrate = 32 * 1000;
        else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 32 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 8 * 1000;

        break;
    case 0010:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 64 * 1000;
            else if (layer == LAYER2)
                bitrate = 48 * 1000;
            else
                bitrate = 40 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 48 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 16 * 1000;

        break;

    case 0011:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 96 * 1000;
            else if (layer == LAYER2)
                bitrate = 56 * 1000;
            else
                bitrate = 48 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 56 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 24 * 1000;
        break;

    case 0100:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 128 * 1000;
            else if (layer == LAYER2)
                bitrate = 64 * 1000;
            else
                bitrate = 56 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 64 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 32 * 1000;

        break;

    case 0101:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 160 * 1000;
            else if (layer == LAYER2)
                bitrate = 80 * 1000;
            else
                bitrate = 64 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 80 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 40 * 1000;
        break;

    case 0110:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 192 * 1000;
            else if (layer == LAYER2)
                bitrate = 96 * 1000;
            else
                bitrate = 80 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 96 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 48 * 1000;
        break;

    case 0111:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 224 * 1000;
            else if (layer == LAYER2)
                bitrate = 112 * 1000;
            else
                bitrate = 96 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 112 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 56 * 1000;
        break;

    case 1000:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 256 * 1000;
            else if (layer == LAYER2)
                bitrate = 128 * 1000;
            else
                bitrate = 112 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 128 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 64 * 1000;
        break;

    case 1001:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 288 * 1000;
            else if (layer == LAYER2)
                bitrate = 160 * 1000;
            else
                bitrate = 128 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 144 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 80 * 1000;
        break;
    case 1010:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 320 * 1000;
            else if (layer == LAYER2)
                bitrate = 192 * 1000;
            else
                bitrate = 160 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 160 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 96 * 1000;
        break;

    case 1011:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 352 * 1000;
            else if (layer == LAYER2)
                bitrate = 224 * 1000;
            else
                bitrate = 192 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 176 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 112 * 1000;
        break;

    case 1100:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 384 * 1000;
            else if (layer == LAYER2)
                bitrate = 256 * 1000;
            else
                bitrate = 224 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 192 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 128 * 1000;
        break;

    case 1101:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 416 * 1000;
            else if (layer == LAYER2)
                bitrate = 320 * 1000;
            else
                bitrate = 256 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 224 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 144 * 1000;
        break;

    case 1110:
        if(type == MPEG_1)
        {
            if(layer == LAYER1)
                bitrate = 448 * 1000;
            else if (layer == LAYER2)
                bitrate = 384 * 1000;
            else
                bitrate = 320 * 1000;
        } else if ((type == MPEG_2 && layer == LAYER1) || (type == MPEG_2_5 && layer == LAYER1))
            bitrate = 256 * 1000;
        else if ((type == MPEG_2 && layer == LAYER2) || (type == MPEG_2_5 && layer == LAYER2))
            bitrate = 160 * 1000;
        break;

    default:
        qDebug()<< "Bitrate not found";
        bitrate = 0;
        break;
    }

    return bitrate;
}

/**
 * @brief ReaderID3V2Tag::getFrequency
 * возвращает частоту дискретизации.
 * индекс частоты находится в 20-21 битах заголовка mp3-фрейма
 * по индексу, определяется значение частоты по таблице FrequencyValue http://id3.org/mp3Frame
 * @param data
 * @return
 */
int ReaderID3V2Tag::getFrequency(QByteArray *data)
{
    int frequency = 0;
    QString binaryStr = QString::number(data->toHex().toLongLong(0,16), 2);
    QString tmpStr = binaryStr.mid(20, 2);
    switch (tmpStr.toInt()) {
    case 00:
        if(type == MPEG_1)
            frequency = 44100;
        else if (type == MPEG_2)
            frequency = 22050;
        else if(type == MPEG_2_5)
            frequency = 11025;
        else
            qDebug() << "Frequency not found";
        break;
    case 01:
        if(type == MPEG_1)
            frequency = 48000;
        else if (type == MPEG_2)
            frequency = 24000;
        else if(type == MPEG_2_5)
            frequency = 12000;
        else
            qDebug() << "Frequency not found";
        break;
    case 10:
        if(type == MPEG_1)
            frequency = 32000;
        else if (type == MPEG_2)
            frequency = 16000;
        else if(type == MPEG_2_5)
            frequency = 8000;
        else
            qDebug() << "Frequency not found";
        break;
    default:
        qDebug() << "Frequency value error";
        break;
    }

    return frequency;
}

/**
 * @brief ReaderID3V2Tag::getChannel
 * возвращает режим канала, используемый в песне.
 * Режим канала назодится в 24-25 битах заголовка mp3 фрейма
 * @param data
 * @return
 */
QString ReaderID3V2Tag::getChannel(QByteArray *data)
{
    QString binaryStr = QString::number(data->toHex().toLongLong(0,16), 2);
    QString tmpStr = binaryStr.mid(24, 2);
    QString channelStr;
    if(tmpStr.isEmpty())
    {
        qDebug() << "Channel value error";
        return QString();
    }
    switch (tmpStr.toInt()) {
    case 00:
        channelStr = "Stereo";
        channelTrack = STEREO;
        break;
    case 01:
        channelStr = "Join Stereo";
        channelTrack = JOIN_STEREO;
        break;
    case 10:
        channelStr = "Dual Channel";
        channelTrack = DUAL_CHANNEL;
        break;
    case 11:
        channelStr = "Mono";
        channelTrack = MONO;
    default:
        qDebug() << "Channel not found";
        break;
    }
    return channelStr;
}

/**
 * @brief ReaderID3V2Tag::getOffset
 * возвращает смещение относительно начала заголовка mp3 фрейма
 * смещение зависит от версии MPEG и режима канала
 * @return
 */
int ReaderID3V2Tag::getOffset()
{
    int offset = 0;
    switch (channelTrack) {
    case 3:
        if(type == MPEG_1)
            offset = 17;
        else
            offset = 9;
        break;
    case 2:
    case 1:
    case 0:
        if(type == MPEG_1)
            offset = 32;
        else
            offset = 17;
        break;
    default:
        break;
    }
    return offset;
}

/**
 * @brief ReaderID3V2Tag::getLenghtTrackVBR
 * возвращает длину песни, при использование метода сжатия данных VBR
 * @param data
 * @return
 * дланна песни определяется по формуле:
 * длительность = количество фреймов * сэмплов на фрейм / частота дискретизации
 */
int ReaderID3V2Tag::getLenghtTrackVBR(QByteArray *data)
{
    int lenght = 0;
    if(freq != 0)
    {
        int numberOfFrame = data->toHex().toInt(0, 16);
        int sampleOnFrame = getSampleOnFrame();
        lenght = numberOfFrame * sampleOnFrame / freq;
    }
    return lenght;
}

/**
 * @brief ReaderID3V2Tag::getSampleOnFrame
 * возвращает количество сэмплов на фрейм
 * @return
 */
int ReaderID3V2Tag::getSampleOnFrame()
{
    int sampleOnFrame = 0;
    switch (layer) {
    case LAYER1:
        sampleOnFrame = 384;
        break;
    case LAYER2:
        sampleOnFrame = 1152;
        break;
    case LAYER3:
        if(type == MPEG_1)
            sampleOnFrame = 1152;
        else
            sampleOnFrame = 576;
        break;
    default:
        break;
    }
    return sampleOnFrame;
}

/**
 * @brief ReaderID3V2Tag::getLenghtTrackCBR
 * возвращает длинну песни, если использовался режим сжатия CBR
 * @param sizeTags - количество бит отведенных для тега ID3V2
 * @param beatRate - битрейт
 * @param ID3V1Tags - флаг присутствия тега ID3V1
 * @return
 * При данном методе сжатия данных используется формула
 * длительность = размер аудиоданных / битрейт( в битах ) * 8
 * размер аудиоданных = общий размер файла - количество бит ID3V2 тега - 128 бит(ID3V1 тег)
 */
int ReaderID3V2Tag::getLenghtTrackCBR(int sizeTags, int beatRate, bool ID3V1Tags)
{
    double lenght = 0;
    if(sizeTags != 0 && beatRate != 0)
    {
        qint64 sizeFile = file->size();
        sizeFile = sizeFile - sizeTags;
        if(ID3V1Tags)
            sizeFile = sizeFile - 128;
        lenght = (double)sizeFile / (double)beatRate * 8.0;
    }
    else
        qDebug() << "Incorrect sie tags or beatRate.";
    return (int)lenght;
}
