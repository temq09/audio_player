#ifndef AUDIOCORE_H
#define AUDIOCORE_H

#include <QAudioOutput>
#include <QAudio>
#include <lib/bass.h>
#include <QDebug>

class AudioCore : public QObject
{
    Q_OBJECT

public:
    AudioCore(QObject *parent = 0, int volume = 50);
    ~AudioCore();

    void PlayTrack(QString path);
    void StopTrack();
    void PauseTrack();

private:
    bool stateAudioSystem;
    bool trackRestart;
    HSTREAM stream;
    HSAMPLE sample;
    HCHANNEL ch;
    void HandleError(int errorCode);
    float volume;


public slots:
    void VolumeChange(int value);
};

#endif // AUDIOCORE_H
