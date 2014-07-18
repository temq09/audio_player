#include "parseplaylist.h"

ParsePlayList::ParsePlayList()
{
    title = "#EXTM3U";
    body = "#EXTINF";
}

ParsePlayList::~ParsePlayList()
{

}

bool ParsePlayList::StartParse(QString pathToPlayList)
{
    QFile* file = new QFile(pathToPlayList);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
       // QMessageBox::critical(this, "Error", "File not open", QMessageBox::Ok);
        qDebug() << "Файл не открылся";
        return false;
    }
    QString str;
    QByteArray arr;
    arr = file->readAll();
    qDebug() << arr;
    //qDebug() << "222- " << &arr.data_ptr()[0];
    int index = 0;


    //считываем первую строку в плейлисте. она определяет формат плэйлиста
    while(arr[index] != '\n')
    {
        str+=arr[index];
        index++;
    }
    //если первая строка не равна #EXTM3U, то формат плэйлиста неизвестен или неправильный, выходим из цикла
    if(str != title)
    {
        qDebug() << "Неизвестный формат";
        file->close();
        delete file;
        return false;
    }
    else
    {
        qDebug() << "Это формат m3u";
    }
    str.clear();
    index++;
    for( ; index< arr.size(); index++)
    {
        //проходим по строке пока не встретим символ ':'
        //после этого делается проверка накопившихся в строке символов с константой которая обозначает начало новой информации о треке
        //если они не совпадают то считываем строку до конца и сбрасываем ее, и все начинается заново
        //если совпадает то начинаем считывать длинну трека до символа ','
        //затем считываем строку до конца, это будет название трека
        //затем считываем строку полностью, это будет путь до трека(корректонсть пути не проверяется)

        switch(arr[index])
        {
        case '\n':
            str.clear();
            break;
        case ':':
            qDebug() << "Начинаю проверять ключевое слово для трека";
            checkInfo(str, &index, arr);
            str.clear();
            break;
        case ',':
            break;
        default:
            str += arr[index];
            break;
        }
    }

    file->close();
    delete file;
    return true;
}

void ParsePlayList::readTime(int *index, QByteArray &arr)
{
    QString time;
    qDebug() << arr[*index];
    while(arr[*index] != ',')
    {
        time += arr[*index];
        (*index)++;
    }
    (*index)++;
    int timeTrack = 0;
    //переводим из строки в число
    bool ok = false;
    timeTrack = time.toInt(&ok, 10);
    if(!ok)
    {
        qDebug() << "Длина трека не известна. Ставим ноль";
    }

    readName(index, arr, timeTrack);
}

void ParsePlayList::readName(int *index, QByteArray &arr, int trackLenght)
{
    QString name;
    while(arr[*index] != '\n')
    {
        name += arr[*index];
        (*index)++;
    }
    (*index)++;
    listTrackName.append(name);
    listTrackTime.insert(name,trackLenght);
    readPath(index, arr, name);
}

void ParsePlayList::readPath(int *index, QByteArray &arr, QString trackName)
{
    QString path;
    while( arr[*index] != '\n')
    {
        path += arr[*index];
        (*index)++;
    }
    listTrackPath.insert(trackName, path);
}

void ParsePlayList::checkInfo(QString str, int *index, QByteArray &arr)
{
    int localIndex = *index;
    qDebug() << localIndex <<" - local index";
    if (str==body)
    {
        (*index)++;
        readTime(index, arr);
    }
    else
    {
        qDebug() << "Error. Not EXTINF ";
        return;
    }
}

QList<QString> ParsePlayList::GetTrackName()
{
    return listTrackName;
}

QMultiMap<QString, QString> ParsePlayList::GetTrackPath()
{
    return listTrackPath;
}

QMultiMap<QString, int> ParsePlayList::GetTrackTime()
{
    return listTrackTime;
}

