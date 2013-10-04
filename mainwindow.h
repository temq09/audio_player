#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QAudioFormat>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QStringListModel>
#include <QAudioDeviceInfo>
#include "audioplayer_core.h"
#include <QAudioOutputSelectorControl>
#include <audiocore.h>
#include "parseplaylist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* main_form;
    QStringList play_list;
    QStringListModel model;
    AudioPlayer_core* player;
    int currentVolume;
    QAudioDeviceInfo deviceInfo;
    QAudioFormat settings;
    QAudioOutput *outputDevice;
    AudioCore *core;

    void refreshList();
    void StartPlay(QString path);

private slots:
    void OpenFile();
    void GetSelectedIndex(QModelIndex index);
    void Play();
    void Stop();
    void Pause();
    void Next();
    void Previous();
    void DurationTrack(int duration);
    void DeviceChanged(int index);
    void OpenPlayList();
};

#endif // MAINWINDOW_H
