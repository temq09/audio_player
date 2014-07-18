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
    QTextStream *stream = new QTextStream(file);
    QString tmpArray = stream->readLine().toUtf8();
    if(!tmpArray.contains(title.toUtf8()))
    {
        qDebug() << "Неправильный формат плэйлиста";
        return false;
    }
    tmpArray.clear();
    tmpArray = stream->readLine();
    while(!tmpArray.isEmpty())
    {
        if(!tmpArray.contains(body.toUtf8()))
            pathToTrack.append(tmpArray.toUtf8());

        tmpArray.clear();
        tmpArray = stream->readLine();
    }
    file->close();
    delete file;
    return true;
}

QStringList ParsePlayList::getPathToTrack()
{
    return pathToTrack;
}

