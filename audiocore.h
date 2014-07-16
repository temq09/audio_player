#ifndef AUDIOCORE_H
#define AUDIOCORE_H

#include <QAudioOutput>
#include <QAudio>
#include <QList>
#include <QDebug>
#include <bass.h>

class AudioCore : public QObject
{
    Q_OBJECT

public:
    AudioCore(QObject *parent = 0, int volume = 50);
    ~AudioCore();

    void playTrack(QString path);
    void stopTrack();
    void pauseTrack();
    void sendSignalTrackEnd();
    void playRadio(QString url);

private:
    bool stateAudioSystem;
    bool trackRestart;
    HSTREAM stream;
    HSAMPLE sample;
    HCHANNEL ch;
    void handleError(int errorCode);
    float volume;
    HFX fx[16];
    static const int channel_count = 16;
    QList<float> freq;
    BASS_DX8_PARAMEQ parametr;
    TAG_ID3 *id3;
    static AudioCore *audiocore;


    void initializeEqlizer();
    static void CALLBACK trackEnd(HSYNC handle, DWORD channel, DWORD data, void *user);

public slots:
    void volumeChange(int value);
    void changeDevice(int index);
    void changeParametrEqalizer(QString name,int value);

signals:
    void switchTrack();
};

#endif // AUDIOCORE_H
