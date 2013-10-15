#include "audiocore.h"

AudioCore::AudioCore(QObject *parent, int volume) :
    QObject(parent),
    volume((float)volume)
{
    //initialization variables
    stateAudioSystem = false;
    trackRestart = false;
    freq << 87.0f << 125.0f << 175.0f << 250.0f << 350.0f << 500.0f << 700.0f << 1000.0f << 1400.0f << 2000.0f << 2800.0f << 4000.0f << 5600.0f << 8000.0f << 11200.0f << 16000.0f;
    //id3 = nullptr;

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

void AudioCore::InitializeEqlizer()
{
    for (int i = 0; i < channel_count; i++)
    {
        fx[i] = BASS_ChannelSetFX(stream,BASS_FX_DX8_PARAMEQ, 0);
        qDebug() << i << " ";
    }
    //fx[channel_count-1] = BASS_ChannelSetFX(stream, BASS_FX_DX8_REVERB, 0);

    parametr.fBandwidth = 1.0f;
    parametr.fGain = 0.0f;

    for (int i = 0; i < channel_count ; i++)
    {
        parametr.fCenter = 87.0f;
        fx[i] = BASS_FXSetParameters(stream, &parametr);
        qDebug() << " Initializ parametr";
    }
}

AudioCore::~AudioCore()
{
    BASS_ChannelStop(stream);
    BASS_StreamFree(stream);
    BASS_Free();
}

void AudioCore::HandleError(int errorCode)
{
    qDebug() << "Код ошибки: "<< errorCode;
}

void CALLBACK AudioCore::TrackEnd(HSYNC handle, DWORD channel, DWORD data, void *user)
{
    qDebug() << "Конец трека";
    Q_ASSERT(user);
    AudioCore* ptr = static_cast<AudioCore*>(user);
    if(ptr)
    {
        qDebug() << "Переключаем трек";
        ptr->SendSignalTrackEnd();
    }
    else
    {
        qDebug() << "Класс не найден";
    }
}

void AudioCore::SendSignalTrackEnd()
{
    emit SwitchTrack();
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
    stream = BASS_StreamCreateFile(FALSE,path.toStdString().c_str() , 0,0, BASS_SAMPLE_FX);
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
        BASS_ChannelSetSync(stream, BASS_SYNC_END | BASS_SYNC_MIXTIME, 0 , TrackEnd, this);
        //InitializeEqlizer();
    }
    if (!BASS_ChannelPlay(stream, trackRestart))
    {
        qDebug() << "Ошибка воспроизведения. Файл audiocore.cpp. Метод PlayTrack";
    }
    else
    {
        qDebug() << "Начинаем воспроизводить трек";
       // BASS_ChannelSetSync(stream, BASS_SYNC_ONETIME, BASS_SYNC_END, SyncProc, 0);
    }
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
void AudioCore::ChangeDevice(int index)
{
    qDebug() << "Инициализируем новое устройство";
    if(!BASS_Init(index+1, 44100,0,0, NULL))
    {
        if(BASS_ErrorGetCode()!= 14)
        {
            qDebug() << "Ошибка инициализации устройства";
            HandleError(BASS_ErrorGetCode());
        }
    }

    qDebug() << "Изменяем устройство вывода трека";
    if (!BASS_ChannelSetDevice(stream,index+1))
    {
        qDebug() << "Изменение устройста неудачно";
        HandleError(BASS_ErrorGetCode());
    }
}

void AudioCore::ChangeParametrEqalizer(QString name, int value)
{
    qDebug() << value;
    qDebug() << name;
    //qDebug() << name;
   /* parametr.fGain = value;
    fx[0] = BASS_FXSetParameters(stream, &parametr);*/
}
