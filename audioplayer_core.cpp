#include "audioplayer_core.h"

AudioPlayer_core::AudioPlayer_core(QObject *parent, int volume) :
    QObject(parent),
    volume(volume)
{    
    player = new QMediaPlayer;
    player->setVolume(volume);
}

AudioPlayer_core::~AudioPlayer_core()
{
    delete player;
}

void AudioPlayer_core::PlayTrack2(QString path)
{
    player->setMedia(QUrl::fromLocalFile(path));
    player->play();
    int duration = player->duration();
    qDebug() << duration;
    emit DurationCurrentTrack(duration);
}

void AudioPlayer_core::PauseTrack()
{
    player->pause();
    qDebug() << player->duration();
}

void AudioPlayer_core::StopTrack()
{
    player->stop();
}

void AudioPlayer_core::VolumeChange(int volume)
{
    player->setVolume(volume);
}
