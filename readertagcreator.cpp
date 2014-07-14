#include "readertagcreator.h"

ReaderTagCreator::ReaderTagCreator()
{

}

ReaderTag * ReaderTagCreator::createReaderTag(QString pathToFile)
{
    qDebug() << pathToFile;
    ReaderTag *readerTag = 0;
    QFile *file = new QFile(pathToFile);
    if(!file->open(QIODevice::ReadOnly))
        return nullptr;
    QByteArray byteArray;
    byteArray = file->read(3);
    if(byteArray.contains("ID3"))
    {
        //qDebug() << "Трек содержит ID3V2 тэг";
        readerTag = new ReaderID3V2Tag(pathToFile);
    }
    else
    {
        if(!file->seek(file->size() - 128))
        {
            file->close();
            return nullptr;
        }
        byteArray.clear();
        byteArray = file->read(3);
        if(byteArray.contains("TAG"))
        {
            //qDebug() << "Трек содержит ID3V1 тег";
            readerTag = new ReaderID3V1Tag(pathToFile);
        }
    }

    file->close();
    return readerTag;
}
