#include "readertag.h"

ReaderTag::ReaderTag(QString pathToFile) : _pathToFile(pathToFile)
{
}

ReaderTag::~ReaderTag()
{
    qDebug() << "dtor ReaderTag";
}

QString ReaderTag::getPathToFile()
{
    return _pathToFile;
}
