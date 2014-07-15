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
    enum typeTrack { MPEG_2_5, MPEG_2, MPEG_1 };
    enum layerIndex { LAYER3, LAYER2, LAYER1 };
    enum channel { STEREO, JOIN_STEREO, DUAL_CHANNEL, MONO };
    enum compressionMode { CBR, VBR, ABR };
    typeTrack type;
    layerIndex layer;
    channel channelTrack;
    int indexLenght;
    int freq;
    QFile *file;

    int getLenghtTags(QByteArray *data);
    QByteArray * readBytesFromFile(int beginINdex, int endIndex);
    QString getInfo(QString tag, QByteArray *data);
    QString getTypeTrack(QByteArray *data);
    int getBeatRate(QByteArray *data);
    int getFrequency(QByteArray *data);
    QString getChannel(QByteArray *data);
    int getOffset();
    int getLenghtTrackVBR(QByteArray *data);
    int getLenghtTrackCBR(int sizeTags, int beatRate, bool ID3V1Tags);
    int getSampleOnFrame();
};

#endif // READERID3V2TAG_H
