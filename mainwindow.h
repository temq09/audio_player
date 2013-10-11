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
#include <QList>
#include <QMultiMap>
#include <QItemSelectionModel>
#include <taglib/taglib.h>
#include <taglib/id3v1tag.h>
#include <taglib/id3v2tag.h>
#include <taglib/id3v2frame.h>
#include <taglib/mpegfile.h>
#include <taglib/fileref.h>
#include <taglib/tstring.h>
#include <taglib/tpropertymap.h>

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
    QItemSelectionModel* selectmodel;
    AudioPlayer_core* player;
    int currentVolume;
    QAudioDeviceInfo deviceInfo;
    QAudioFormat settings;
    QAudioOutput *outputDevice;
    AudioCore *core;
    QList<QString> trackName;
    QMultiMap<QString, QString> trackPath;
    QMultiMap<QString, int> trackTime;
    int currentPlayTrack;
    int fx[];
    int channel_count;
    TagLib::ID3v2::Tag* tag;


    void refreshList();
    void StartPlay(QString path);
    void parseFileList(QStringList &file_list);
    void initializeEqalizerScrollBar();
    void changeFocusToNextTrack(int row);

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
