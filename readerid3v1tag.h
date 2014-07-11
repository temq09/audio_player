#ifndef READERID3V1TAG_H
#define READERID3V1TAG_H
#include "readertag.h"

class ReaderID3V1Tag : public ReaderTag
{
public:
    ReaderID3V1Tag(QString pathToFile);
    ~ReaderID3V1Tag();

    TagInfo getTag();

private:
    int byteOfTag;
    int headerIndex;
    int titleIndex;
    int artistIndex;
    int albumIndex;
    int genreIndex;
    int yearIndex;
    int commentIndex;
    QFile *file;

    QByteArray getInfo(int beginIndex, int endIndex, QByteArray *source);
};

#endif // READERID3V1TAG_H
