#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_form(new Ui::MainWindow)
{
    main_form->setupUi(this);

    //setting variables
    currentVolume = 50;
    //deviceInfo = QAudioDeviceInfo::defaultOutputDevice();
    player = new AudioPlayer_core(this, currentVolume);
    //settings = new QAudioFormat();

    //settings form
    main_form->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    main_form->sb_volume->setValue(currentVolume);
    foreach (const QAudioDeviceInfo &device, QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)) {
        main_form->cb_device->addItem(device.deviceName(), qVariantFromValue(device));
    }


    //connect block
    connect(main_form->btn_OpenFile, SIGNAL(clicked()), this, SLOT(OpenFile()));
    connect(main_form->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetSelectedIndex(QModelIndex)));
    connect(main_form->btn_Play, SIGNAL(clicked()), this, SLOT(Play()));
    connect(main_form->btn_Pause, SIGNAL(clicked()), this, SLOT(Pause()));
    connect(main_form->btn_Stop, SIGNAL(clicked()), this, SLOT(Stop()));
    connect(main_form->btn_Next, SIGNAL(clicked()), this, SLOT(Next()));
    connect(main_form->btn_Previous, SIGNAL(clicked()), this, SLOT(Previous()));
    connect(player,SIGNAL(DurationCurrentTrack(int)), this, SLOT(DurationTrack(int)));
    //connect(main_form->sb_volume, SIGNAL(valueChanged(int)), player, SLOT(VolumeChange(int)));
    connect(main_form->cb_device, SIGNAL(activated(int)), this, SLOT(DeviceChanged(int)));

    core = new AudioCore(this, currentVolume);
    //connect(main_form->sb_volume, SIGNAL(valueChanged(int)), core, SLOT(VolumeChange(int)));
}

MainWindow::~MainWindow()
{
    delete main_form;
    delete player;
    delete core;
}

void MainWindow::OpenFile()
{
    QStringList file_list = QFileDialog::getOpenFileNames(this,
                                                          "Открыть файлы",
                                                          "C:/",
                                                          "Audio (*.mp3 *.raw *.waw);;All files (*.*)");

    QStringList::const_iterator constIterator;
    for ( constIterator = file_list.constBegin(); constIterator != file_list.constEnd(); constIterator++)
    {
        play_list.append((*constIterator).toLocal8Bit().constData());
    }
    refreshList();
}

void MainWindow::refreshList()
{
    model.setStringList(play_list);
    main_form->listView->setModel(&model);

    qDebug() << "Refresh play list";
}

void MainWindow::GetSelectedIndex(QModelIndex index)
{
    qDebug() << index.row();
    //emit StartPlay(index);
    QString path = play_list.at(index.row());
    qDebug() << path;
    StartPlay(path);
}

void MainWindow::StartPlay(QString path)
{
    //player->PlayTrack2(path);
    core->PlayTrack(path);
}

void MainWindow::Play()
{
    int index = -1;
    index = main_form->listView->currentIndex().row();
    if(index != -1)
    {
        QString path = play_list.at(index);
        StartPlay(path);
    }
}

void MainWindow::Pause()
{
    //player->PauseTrack();
    core->PauseTrack();
}

void MainWindow::Stop()
{
    //player->StopTrack();
    core->StopTrack();
}

void MainWindow::Next()
{
    int index = -1;
    index = main_form->listView->currentIndex().row() + 1;
    if (index != -1)
    {
        QString path = play_list.at(index);
        StartPlay(path);
    }
}

void MainWindow::Previous()
{
    int index = -2;
    index = main_form->listView->currentIndex().row()-1;
    if (index == -2)
    {
        return;
    }
    else
    {
        if (index == -1)
        {
            index = 0;
        }
        QString path = play_list.at(index);
        StartPlay(path);
    }
}

void MainWindow::DurationTrack(int duration)
{
    qDebug() <<"Продолжительность песни" << duration;
}

void MainWindow::DeviceChanged(int index)
{
    qDebug() << "Changed device";
}
