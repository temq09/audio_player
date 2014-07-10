#ifndef READERTAG_H
#define READERTAG_H
#include <QString>
#include <QDebug>
#include <QByteArray>

typedef struct TagInfo{
    TagInfo() : length(0),
        beatRate(0),
        year(0),
        trackNum(0),
        size(0)
    { }

    QString artist;
    QString title;
    QString genre;
    QString album;
    int length;
    int beatRate;
    int year;
    int trackNum;
    int size;
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
