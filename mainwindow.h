#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QStringListModel>
#include "modernslider.h"
#include "audiocore.h"
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
#include "form_addradio.h"

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
    int currentVolume;
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
    form_addRadio* form_Radio;


    void refreshList();
    void StartPlay(QString path);
    void StartPlayRadio(QString path);
    void ChoosePlay(int index);
    void parseFileList(QStringList &file_list);
    void initializeEqalizerScrollBar();
    void changeFocusToNextTrack(int row);
    //void ConnectedSlyderSignalsAndSlots();

private slots:
    void OpenFile();
    void GetSelectedIndex(QModelIndex index);
    void Play();
    void Stop();
    void Pause();
    void Next();
    void Previous();
    void OpenPlayList();
    void SavePlayList();
    void Info();
    void DeleteFailFromDisk();
    void DeleteFailFromPlayList();
    void Mute(bool state);
    void CheckMute();
    void ClearFormInfo();
    void AddRadio();
    void AddRadioToPlayList(QString url, QString nameRadio);
    void ClearFormAddRadio();

public slots:
    //void handleSliderMoved(QString objectName);

signals:
    void SliderChangeWithName(QString name, int value);

};

#endif // MAINWINDOW_H
