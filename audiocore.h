#ifndef AUDIOCORE_H
#define AUDIOCORE_H

#include <QAudioOutput>
#include <QAudio>
#include <QList>
#include <QDebug>
#include "src/bass/bass.h"

class AudioCore : public QObject
{
    Q_OBJECT

public:
    AudioCore(QObject *parent = 0, int volume = 50);
    ~AudioCore();

    void PlayTrack(QString path);
    void StopTrack();
    void PauseTrack();
    void SendSignalTrackEnd();
    void PlayRadio(QString url);

private:
    bool stateAudioSystem;
    bool trackRestart;
    HSTREAM stream;
    HSAMPLE sample;
    HCHANNEL ch;
    void HandleError(int errorCode);
    float volume;
    HFX fx[16];
    static const int channel_count = 16;
    QList<float> freq;
    BASS_DX8_PARAMEQ parametr;
    TAG_ID3* id3;
    static AudioCore* audiocore;


    void InitializeEqlizer();
    static void CALLBACK TrackEnd(HSYNC handle, DWORD channel, DWORD data, void *user);

public slots:
    void VolumeChange(int value);
    void ChangeDevice(int index);
    void ChangeParametrEqalizer(QString name,int value);

signals:
    void SwitchTrack();
};

#endif // AUDIOCORE_H
