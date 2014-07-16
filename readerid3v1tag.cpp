#include "readerid3v1tag.h"

ReaderID3V1Tag::ReaderID3V1Tag(QString pathToFile) : ReaderTag(pathToFile),
    byteOfTag(128),
    headerIndex(0),
    titleIndex(3),
    artistIndex(33),
    albumIndex(63),
    yearIndex(93),
    commentIndex(97),
    genreIndex(127)
{
    file = new QFile(getPathToFile().toUtf8());
    file->open(QIODevice::ReadOnly);
}

ReaderID3V1Tag::~ReaderID3V1Tag()
{
    if(file->isOpen())
        file->close();
    delete file;
}

TagInfo ReaderID3V1Tag::getTag()
{
    qDebug() << getPathToFile();
    TagInfo tagInfo;
    int offset = file->size() - byteOfTag;
    if(file->seek(offset))
    {
        QByteArray byteArray;
        QDataStream input;
        input.setDevice(file);
        byteArray.resize(byteOfTag);
        input.readRawData(byteArray.data(), byteOfTag);
        QByteArray tagArray = byteArray.toHex();
        tagInfo.title = QString(getInfo(titleIndex * 2, artistIndex * 2, &tagArray ));
        tagInfo.artist = QString(getInfo(artistIndex * 2, albumIndex * 2, &tagArray));
        tagInfo.album = QString(getInfo(albumIndex * 2, yearIndex * 2, &tagArray));
        tagInfo.year = getInfo(yearIndex * 2, commentIndex * 2, &tagArray).toInt();
        tagInfo.genre = QString(getInfo(genreIndex * 2 - 1, genreIndex * 2, &tagArray));
    }
    return tagInfo;
}

QByteArray ReaderID3V1Tag::getInfo(int beginIndex, int endIndex, QByteArray *source)
{
    if(beginIndex < source->length() && endIndex <= source->length())
    {
        QByteArray tmpArr;
        for(int i = beginIndex; i < endIndex; i++)
        {
            tmpArr.append(source->at(i));
        }
        return QByteArray::fromHex(tmpArr);
    }
    else
    {
        qDebug() << "Index out of range!";
        return nullptr;
    }
}
