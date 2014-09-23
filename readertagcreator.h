#ifndef READERTAGCREATOR_H
#define READERTAGCREATOR_H
#include "readerid3v1tag.h"
#include "readerid3v2tag.h"

class ReaderTagCreator
{
public:
    ReaderTagCreator();
    static ReaderTag *createReaderTag(const QString &pathToFile);
};

#endif // READERTAGCREATOR_H
