#include "readertagcreator.h"

ReaderTagCreator::ReaderTagCreator()
{

}

ReaderTag * ReaderTagCreator::createReaderTag(QString pathToFile)
{
    ReaderTag *readerTag = new ReaderID3V1Tag(pathToFile);

    return readerTag;
}
