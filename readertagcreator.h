#ifndef READERTAGCREATOR_H
#define READERTAGCREATOR_H
#include "readerid3v1tag.h"
#include "readerid3v2tag.h"
#include <QDataStream>
#include <QByteArray>

class ReaderTagCreator
{
public:
    ReaderTagCreator();
    static ReaderTag *createReaderTag(QString pathToFile);
};

#endif // READERTAGCREATOR_H
