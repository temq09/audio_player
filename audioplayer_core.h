#ifndef AUDIOPLAYER_CORE_H
#define AUDIOPLAYER_CORE_H

#include <QObject>
#include <QAudioOutput>
#include <QFile>
#include <QIODevice>
#include <QDebug>
#include <QMediaPlayer>

class AudioPlayer_core : public QObject
{
    Q_OBJECT
public:
    explicit AudioPlayer_core(QObject *parent = 0, int volume = 50);
    ~AudioPlayer_core();
    void PlayTrack(QString path);
    void StopTrack();
    void PauseTrack();
    void PreviousTrack(QString path);
    void PlayTrack2(QString path);

private:
    //properties
    QAudioOutput* audio;
    QMediaPlayer* player;
    int volume;

    //methods

public slots:
    void VolumeChange(int volume);


signals:
    void DurationCurrentTrack(int duration);
};

#endif // AUDIOPLAYER_CORE_H
