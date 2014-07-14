#include "readerid3v2tag.h"

ReaderID3V2Tag::ReaderID3V2Tag(QString pathToFile) : ReaderTag(pathToFile)
{
    indexLenght = 6;
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

TagInfo ReaderID3V2Tag::getTag()
{
    //qDebug() << "Read ID3V2 tag";
    TagInfo tagInfo;
    int offset = indexLenght;
    if(file->seek(offset))
    {
        int lenght = 4;
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
        tagInfo.beatRate = getInfo("TBPM", array).toInt();
        //qDebug() << tagInfo.album;
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
 * при выборке данных используется функция QByteArray::mid. При вычислении индекса начал, и длинны происходит корректировка на значение 1.
 * Это сделанно аз-за того, что первым символом является '00'.
 */
QString ReaderID3V2Tag::getInfo(QString tag, QByteArray *data)
{
    int index = data->indexOf(tag);
    QByteArray tagsData = data->mid(index + tag.size(), 4);
    if(tagsData.isEmpty())
    {
        qDebug() << "Error while parse " << tag;
        return QString();
    }
    int sizeTag = tagsData.toHex().toInt(0, 16);
    //qDebug() << sizeTag;
    tagsData.clear();
    tagsData = data->mid(index + 10 + 1, sizeTag - 1 );
    if(tagsData.isEmpty())
    {
        qDebug() << "Error while parse " << tag;
        return QString();
    }
    QString result = tagsData;
    qDebug() << result ;
    return result;
}
