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
#include "modernslider.h"
#include "audioplayer_core.h"
#include <QAudioOutputSelectorControl>
#include <audiocore.h>
#include "parseplaylist.h"
#include <QList>
#include <QMultiMap>
#include <QItemSelectionModel>
#include <QAction>
#include <taglib/taglib.h>
#include <taglib/id3v1tag.h>
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include "form.h"

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
    int channel_count;
    QAction* act_Info;
    QAction* act_deleteFailFromPlayList;
    QAction* act_deleteFailFromDisk;
    modernSlider* mySlider;
    Form* form_info;

    void refreshList();
    void StartPlay(QString path);
    void parseFileList(QStringList &file_list);
    void initializeEqalizerScrollBar();
    void changeFocusToNextTrack(int row);
    void ConnectedSlyderSignalsAndSlots();

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
    void SavePlayList();
    void Info();
    void DeleteFailFromDisk();
    void DeleteFailFromPlayList();

public slots:
    void handleSliderMoved(QString objectName);

signals:
    void SliderChangeWithName(QString name, int value);

};

#endif // MAINWINDOW_H
