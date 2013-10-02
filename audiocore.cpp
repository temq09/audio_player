#include "audiocore.h"

AudioCore::AudioCore(QObject *parent, int volume) :
    QObject(parent),
    volume((float)volume)
{
    //initialization variables
    stateAudioSystem = false;
    trackRestart = false;

    //initialization audioSystem
    stateAudioSystem = BASS_Init(-1,44100, 0,0, NULL);
    if (stateAudioSystem)
    {
        qDebug() << "Инициализация произведена успешно";
    }
    else
    {
        qDebug() <<"Error";
        HandleError(BASS_ErrorGetCode());
    }

    //connect signals and slots

}

AudioCore::~AudioCore()
{
    BASS_ChannelStop(stream);
    BASS_StreamFree(stream);
}

void AudioCore::HandleError(int errorCode)
{
    qDebug() << "Код ошибки: "<< errorCode;
}

void AudioCore::PlayTrack(QString path)
{
    if(BASS_ChannelIsActive(stream) == BASS_ACTIVE_PAUSED)
    {
        qDebug() << "Продолжаем воспроизведение файла";
        if(!BASS_ChannelPlay(stream, trackRestart))
        {
            qDebug() << "Ошибка возобновления воспроизведения файла";
            HandleError(BASS_ErrorGetCode());

        }
        return;
    }

    if(BASS_ChannelIsActive(stream) == BASS_ACTIVE_PLAYING)
    {
        BASS_ChannelStop(stream);
        BASS_StreamFree(stream);
    }

    qDebug() << "Создаем stream";
    stream = BASS_StreamCreateFile(FALSE,path.toStdString().c_str() , 0,0,0);
    if(!stream)
    {
        qDebug() << "Ошибка создания потока";
        qDebug() << path.data();
        return ;
    }
    else
    {
        qDebug() <<"Ok";
        VolumeChange(volume);
    }
    if (!BASS_ChannelPlay(stream, trackRestart))
    {
        qDebug() << "Ошибка воспроизведения. Файл audiocore.cpp. Метод PlayTrack";
    }
    else
        qDebug() << "Начинаем воспроизводить трек";


}

void AudioCore::StopTrack()
{
    if(BASS_ChannelIsActive(stream) == BASS_ACTIVE_PLAYING || BASS_ChannelIsActive(stream) == BASS_ACTIVE_PAUSED)
    {
        qDebug() << "Останавливаем трек";
        if (!BASS_ChannelStop(stream))
        {
            qDebug() <<"Возникла ошибка при остановке трека";
            HandleError(BASS_ErrorGetCode());
        }
    }
}

void AudioCore::PauseTrack()
{
    if(BASS_ChannelIsActive(stream) == BASS_ACTIVE_PLAYING)
    {
        qDebug() << "Ставим трек на паузу";
        if(!BASS_ChannelPause(stream))
        {
            qDebug() << "Возникла ошибка при установки трека на паузу";
            HandleError(BASS_ErrorGetCode());
        }
    }
}

void AudioCore::VolumeChange(int value)
{
    if (!BASS_ChannelSetAttribute(stream,BASS_ATTRIB_VOL,(float)value/100))
    {
        qDebug() << "Возникла ошибка при изменении громкости";
        HandleError(BASS_ErrorGetCode());
    }
}
