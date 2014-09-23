#include "readertagcreator.h"

ReaderTagCreator::ReaderTagCreator()
{

}

ReaderTag * ReaderTagCreator::createReaderTag(const QString &pathToFile)
{
    qDebug() << pathToFile;
    ReaderTag *readerTag = 0;
    QString tmp = QString(pathToFile.unicode());
    QFile *file = new QFile(tmp);
    if(!file->open(QIODevice::ReadOnly))
        return nullptr;
    QByteArray byteArray;
    byteArray = file->read(3);
    if(byteArray.contains("ID3"))
    {
        //qDebug() << "Трек содержит ID3V2 тэг";
        readerTag = new ReaderID3V2Tag(tmp);
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
            readerTag = new ReaderID3V1Tag(tmp);
        }
        else
            readerTag = new ReaderID3V2Tag(tmp); // попытка прочитать информацию из фреймов, при отсутствие тегов.
    }

    file->close();
    return readerTag;
}
