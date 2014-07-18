#ifndef READERTAG_H
#define READERTAG_H
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QFile>
#include <QDataStream>
#include <QElapsedTimer>

typedef struct TagInfo{
    TagInfo() : length(0),
        beatRate(0),
        year(0),
        size(0),
        frequency(0)
    { }

    QString artist;
    QString title;
    QString genre;
    QString album;
    QString trackNum;
    QString trackType;
    QString channel;
    QString pathToFile;
    int length;
    int beatRate;
    int year;    
    quint64 size;
    int frequency;
} TagInfo;

class ReaderTag
{
public:
    ReaderTag(QString pathToFile);
    ~ReaderTag();
    virtual TagInfo getTag() = 0;
    QString getPathToFile();

private:
    QString _pathToFile;
    TagInfo tag;
};

#endif // READERTAG_H
