#ifndef READERID3V2TAG_H
#define READERID3V2TAG_H
#include "readertag.h"

class ReaderID3V2Tag : public ReaderTag
{
public:
    ReaderID3V2Tag(QString pathToFile);
    ~ReaderID3V2Tag();
    TagInfo getTag();
};

#endif // READERID3V2TAG_H
