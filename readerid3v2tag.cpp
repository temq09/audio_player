#include "readerid3v2tag.h"

ReaderID3V2Tag::ReaderID3V2Tag(QString pathToFile) : ReaderTag(pathToFile)
{
}

ReaderID3V2Tag::~ReaderID3V2Tag()
{

}

TagInfo ReaderID3V2Tag::getTag()
{
    qDebug() << "Read ID3V2 tag";
    TagInfo tagInfo;

    return tagInfo;

}
