#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QStringListModel>
#include <QItemSelectionModel>
#include <QAction>
#include <readertag.h>
#include <QListWidgetItem>
#include <QListWidget>

#include "modernslider.h"
#include "audiocore.h"
#include "parseplaylist.h"
#include "form.h"
#include "form_addradio.h"
#include "readertagcreator.h"
#include "playlistitem.h"

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
    Ui::MainWindow *main_form;
    QStringList play_list;
    QStringListModel model;
    QItemSelectionModel *selectmodel;
    int currentVolume;
    AudioCore *core;
    QList<PlayListItem*> playList;
    int currentPlayTrack;
    int channel_count;
    QAction *act_Info;
    QAction *act_deleteFailFromPlayList;
    QAction *act_deleteFailFromDisk;
    modernSlider *mySlider;
    Form *form_info;

    void startPlay(QString path);
    void startPlayRadio(QString path);
    void choosePlay(int index);
    void parseFileList(QStringList &file_list);
    void initializeEqalizerScrollBar();
    void changeFocusToNextTrack(int row);
    void addItemToPlayList(TagInfo tag);
    //void ConnectedSlyderSignalsAndSlots();

private slots:
    void openFile();
    //void getSelectedIndex(QModelIndex index);
    void play();
    void stop();
    void pause();
    void next();
    void previous();
    void openPlayList();
    void savePlayList();
    void info();
    void deleteFailFromDisk();
    void deleteFailFromPlayList();
    void mute(bool state);
    void checkMute();
    void clearFormInfo();
    void addRadio();
    void addRadioToPlayList(QString url, QString nameRadio);

public slots:
    //void handleSliderMoved(QString objectName);

signals:
    void sliderChangeWithName(QString name, int value);

};

#endif // MAINWINDOW_H
