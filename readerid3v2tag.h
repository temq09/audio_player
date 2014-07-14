#ifndef READERID3V2TAG_H
#define READERID3V2TAG_H
#include "readertag.h"
#include <QChar>

class ReaderID3V2Tag : public ReaderTag
{
public:
    ReaderID3V2Tag(QString pathToFile);
    ~ReaderID3V2Tag();
    TagInfo getTag();

private:
    int indexLenght;
    QFile *file;

    int getLenghtTags(QByteArray *data);
    QByteArray * readBytesFromFile(int beginINdex, int endIndex);
    QString getInfo(QString tag, QByteArray *data);
};

#endif // READERID3V2TAG_H
