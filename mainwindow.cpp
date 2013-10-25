#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
using namespace TagLib;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_form(new Ui::MainWindow)
{
    main_form->setupUi(this);

    //setting variables
    currentVolume = 50;
    currentPlayTrack = 0;
    core = new AudioCore(this, currentVolume);
    form_Radio = NULL;
    /*mySlider = new modernSlider(this);
    mySlider->setObjectName("slider 1");
    mySlider->setWindowIconText("asdf");
    main_form->horizontalLayout_4->addWidget(mySlider);*/

    //settings form
    main_form->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    main_form->sb_volume->setValue(currentVolume);
    foreach (const QAudioDeviceInfo &device, QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)) {
        main_form->cb_device->addItem(device.deviceName(), qVariantFromValue(device));
    }
    main_form->listView->setDragDropMode(QAbstractItemView::DragDrop);

    //connect block
    //ConnectedSlyderSignalsAndSlots();
    connect(main_form->btn_OpenFile, SIGNAL(clicked()), this, SLOT(OpenFile()));
    connect(main_form->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetSelectedIndex(QModelIndex)));
    connect(main_form->btn_Play, SIGNAL(clicked()), this, SLOT(Play()));
    connect(main_form->btn_Pause, SIGNAL(clicked()), this, SLOT(Pause()));
    connect(main_form->btn_Stop, SIGNAL(clicked()), this, SLOT(Stop()));
    connect(main_form->btn_Next, SIGNAL(clicked()), this, SLOT(Next()));
    connect(main_form->btn_Previous, SIGNAL(clicked()), this, SLOT(Previous()));
    connect(main_form->sb_volume, SIGNAL(valueChanged(int)), core, SLOT(VolumeChange(int)));
    connect(main_form->sb_volume, SIGNAL(valueChanged(int)), this, SLOT(CheckMute()));
    connect(core, SIGNAL(SwitchTrack()), this, SLOT(Next()));
    connect(main_form->cb_device, SIGNAL(activated(int)), core, SLOT(ChangeDevice(int)));
    connect(main_form->btn_OpenPlayList, SIGNAL(clicked()), this, SLOT(OpenPlayList()));
    connect(core, SIGNAL(SwitchTrack()), this, SLOT(Next()));
    connect(main_form->btn_SavePlayList, SIGNAL(clicked()), this, SLOT(SavePlayList()));
    connect(this, SIGNAL(SliderChangeWithName(QString,int)), core, SLOT(ChangeParametrEqalizer(QString,int)));
    connect(main_form->cBox_Mute, SIGNAL(toggled(bool)), this, SLOT(Mute(bool)));
    connect(main_form->btn_AddRadio, SIGNAL(clicked()), this, SLOT(AddRadio()));
    //connect(main_form->slider_87, SIGNAL, core, SLOT(ChangeParametrEqalizer(int)));
    main_form->listView->setContextMenuPolicy(Qt::ActionsContextMenu);
    act_Info = new QAction("Информация о файле", main_form->listView);
    act_deleteFailFromPlayList = new QAction("Удалить файл из плейлиста", main_form->listView);
    act_deleteFailFromDisk = new QAction("Удалить файл с диска", main_form->listView);


    connect(act_Info, SIGNAL(triggered()),this, SLOT(Info()));
    connect(act_deleteFailFromPlayList, SIGNAL(triggered()), this, SLOT(DeleteFailFromPlayList()));
    connect(act_deleteFailFromDisk, SIGNAL(triggered()), this, SLOT(DeleteFailFromDisk()));
    main_form->listView->addAction(act_Info);
    main_form->listView->addAction(act_deleteFailFromPlayList);
    main_form->listView->addAction(act_deleteFailFromDisk);
}

/*void MainWindow::ConnectedSlyderSignalsAndSlots()
{
    connect(main_form->slider_87, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_125, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_175, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_250, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_350, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_500, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_700, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_1000, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_1400, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_2000, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_2800, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_4000, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_5600, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_8000, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_11200, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
    connect(main_form->slider_16000, SIGNAL(objectNameChanged(QString)), this, SLOT(handleSliderMoved(QString)));
}*/



void MainWindow::initializeEqalizerScrollBar()
{

}

MainWindow::~MainWindow()
{
    qDebug() << "Erase mainform";
    delete main_form;
    delete core;

}

void MainWindow::OpenFile()
{
    QStringList file_list = QFileDialog::getOpenFileNames(this,
                                                          "Открыть файлы",
                                                          "C:/",
                                                          "Audio (*.mp3 *.raw *.waw);;All files (*.*)");

    qDebug() << "Парсим";
    parseFileList(file_list);
    qDebug() << "Обновляем";
    refreshList();
}

void MainWindow::parseFileList(QStringList &file_list)
{
    QStringList::const_iterator constIterator;
    for ( constIterator = file_list.constBegin(); constIterator != file_list.constEnd(); constIterator++)
    {
        qDebug() << "открываем";
        TagLib::MPEG::File mp3file((*constIterator).toUtf8().constData());
        //TagLib::MPEG::File mp3file("C:\\tmp\\test.mp3");
        qDebug() << "Открыли";
        if (mp3file.hasID3v2Tag())
        {
            qDebug() << "Создаем тег";
            TagLib::ID3v2::Tag* mp3tag = mp3file.ID3v2Tag();
            qDebug() << "Артист";
            QString artist = QString("%1 - %2").arg(mp3tag->artist().to8Bit().data()).arg(mp3tag->title().to8Bit().data() );
            qDebug() << "длинна";
            int duration = mp3file.audioProperties()->length();
            qDebug() << "Добавляем в контейрнеры";
            trackName.append(artist);
            trackPath.insert(artist, (*constIterator).toLocal8Bit().constData());
            trackTime.insert(artist, duration);
        }
        else if(mp3file.hasID3v1Tag())
        {
            qDebug() << "Создаем тег в1";
            TagLib::ID3v1::Tag* mp3tag = mp3file.ID3v1Tag();
            QString artist = QString("%1 - %2").arg(mp3tag->artist().to8Bit().data()).arg(mp3tag->title().to8Bit().data());
            int duration = mp3file.audioProperties()->length();
            trackName.append(artist);
            trackPath.insert(artist, (*constIterator).toLocal8Bit().constData());
            trackTime.insert(artist, duration);
        }
    }
}

void MainWindow::OpenPlayList()
{
    QString playList = QFileDialog::getOpenFileName(this,
                                                        "Открыть плейлист",
                                                        "C:/",
                                                        "playlist (*.m3u)");
    ParsePlayList* parsePlaylist = new ParsePlayList;

    if(parsePlaylist->StartParse(playList))
    {
        trackName = parsePlaylist->GetTrackName();
        trackPath = parsePlaylist->GetTrackPath();
        trackTime = parsePlaylist->GetTrackTime();
        refreshList();
    }

    delete parsePlaylist;
}

void MainWindow::refreshList()
{
    model.setStringList(trackName);
    main_form->listView->setModel(&model);

    qDebug() << "Refresh play list";
}

void MainWindow::GetSelectedIndex(QModelIndex index)
{
    qDebug() << index.row();
    /*QString path = trackPath.value(trackName.at(index.row()));
    qDebug() << path;
    StartPlay(path);*/
    ChoosePlay(index.row());
    currentPlayTrack = index.row();
}

void MainWindow::StartPlay(QString path)
{
    core->PlayTrack(path);
}

void MainWindow::StartPlayRadio(QString path)
{
    core->PlayRadio(path);
}

void MainWindow::Play()
{
    int index = -1;
    index = main_form->listView->currentIndex().row();
    if(index != -1)
    {
        ChoosePlay(index);
    }
}

void MainWindow::Pause()
{
    if(trackName.isEmpty())
    {
        qDebug() << "Плей лист пустой, него ставить на паузу";
        return;
    }
    if(trackTime.value(trackName.at(currentPlayTrack)) == -1)
    {
        QMessageBox mes;
        mes.setText("Нельзя ставить радио на паузу.");
        mes.exec();
        return;
    }
    core->PauseTrack();
}

void MainWindow::Stop()
{
    core->StopTrack();
}

void MainWindow::Next()
{
    int index = -1;
    if(main_form->cBox_random->isChecked())
    {
        int range = trackName.size();
        index = rand()%range;
    }
    else
    {
        index = currentPlayTrack+1;
    }

    if (index != -1)
    {
        if(index > trackName.size()-1)
        {
            index = 0;
        }
        ChoosePlay(index);
        changeFocusToNextTrack(index);
    }
}

void MainWindow::Previous()
{
    int index = -2;
    index = currentPlayTrack-1;
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
        ChoosePlay(index);
        changeFocusToNextTrack(index);
    }
}

void MainWindow::ChoosePlay(int index)
{
    QString path = trackPath.value(trackName.at(index));
    currentPlayTrack = index;
    if(trackTime.value(trackName.at(index)) == -1)
    {
        StartPlayRadio(path);
    }
    else if (trackTime.value(trackName.at(index)) > 0)
    {
        StartPlay(path);
    }
}

void MainWindow::changeFocusToNextTrack(int row)
{
    main_form->listView->selectionModel()->select(model.index(row, 0), QItemSelectionModel::ClearAndSelect);
}

void MainWindow::SavePlayList()
{
    const QString title = "#EXTM3U";
    const QString body = "#EXTINF";

    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Playlist"),
                                                    QDir::currentPath(),
                                                    tr("PlayList (*.m3u)"));
    qDebug() << filename;

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Файл не открыт.";
    }
    else
    {
        QTextStream out(&file);
        out << title << "\n\n";

        QList<QString>::const_iterator constIterator;
        for(constIterator = trackName.constBegin(); constIterator != trackName.constEnd(); constIterator++)
        {
            QString artist = (*constIterator).toLocal8Bit().constData();
            out << body <<":" << trackTime.value(artist) << "," << artist << "\n" << trackPath.value(artist) << "\n\n";
        }
    }
}

/*void MainWindow::handleSliderMoved(QString objectName)
{
    qDebug() << "222111";
    //connect(this, SIGNAL(sliderChangeWithName(QString,int)), core, SLOT(ChangeParametrEqalizer(QString,int)));
    int currentValue;
    switch(objectName.toInt())
    {
    case 'slider_87': currentValue = main_form->slider_87->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_125': currentValue = main_form->slider_125->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_175': currentValue = main_form->slider_175->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_250': currentValue = main_form->slider_250->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_350': currentValue = main_form->slider_350->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_500': currentValue = main_form->slider_500->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_700': currentValue = main_form->slider_700->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_1000': currentValue = main_form->slider_1000->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_1400': currentValue = main_form->slider_1400->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_2000': currentValue = main_form->slider_2000->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_2800': currentValue = main_form->slider_2800->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_4000': currentValue = main_form->slider_4000->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_5600': currentValue = main_form->slider_5600->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_8000': currentValue = main_form->slider_8000->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_11200': currentValue = main_form->slider_11200->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    case 'slider_16000': currentValue = main_form->slider_16000->value();
        emit SliderChangeWithName(objectName, currentValue);
        break;

    default: qDebug() << "Такой слайдер не найден";

    }
}*/

void MainWindow::DeleteFailFromPlayList()
{
    int index = -1;
    index = main_form->listView->currentIndex().row();
    if(index != -1)
    {
        trackPath.remove(trackName.at(index));
        trackTime.remove(trackName.at(index));
        trackName.removeAt(index);
        refreshList();
    }
}

void MainWindow::DeleteFailFromDisk()
{
    qDebug() << "fdfsfddddd";
}

void MainWindow::Info()
{
    int index = -1;
    index = main_form->listView->currentIndex().row();
    if (index != -1)
    {
        QString artist = "Неизвестен";
        QString title = "Нет названия";
        QString album = "Неизвестен";
        QString genre = "Неизвестен";
        int year = 0;
        int numTrack = 0;
        int lenght = 0;
        int bitrate = 0;
        int size = 0;
        qDebug() << "1";
        QString PathToFile = trackPath.value(trackName.at(index));
        qDebug() << "2";
        TagLib::MPEG::File mp3file(PathToFile.toLocal8Bit().constData());
        qDebug() << "3";
        if(mp3file.hasID3v2Tag())
        {
            qDebug() << "4";
            TagLib::ID3v2::Tag* tag = mp3file.ID3v2Tag();
            qDebug() << "5";
            artist = tag->artist().to8Bit().data();
            album = tag->album().to8Bit().data();
            genre = tag->genre().to8Bit().data();
            title = tag->title().to8Bit().data();
            year = tag->year();
            numTrack = tag->track();
            lenght = mp3file.audioProperties()->length();
            bitrate = mp3file.audioProperties()->bitrate();
            size = mp3file.length();
            form_info = new Form(this, title, artist, album, genre, year, numTrack, lenght, bitrate, size );
            form_info->setWindowFlags(Qt::Window);
            form_info->show();
            connect(form_info, SIGNAL(destroyed()), this, SLOT(ClearFormInfo()));
        }
    }
}

void MainWindow::ClearFormInfo()
{
    delete form_info;
    disconnect(form_info, SIGNAL(destroyed()), this, SLOT(ClearFormInfo()));
}

void MainWindow::Mute(bool state)
{
    if(state == true)
    {
        qDebug() << "Выключаем звук";
        core->VolumeChange(0);
    }
    else if(state == false)
    {
        qDebug() << "Включаем звук";
        core->VolumeChange(main_form->sb_volume->value());
    }
}

void MainWindow::CheckMute()
{
    if(main_form->cBox_Mute->isChecked())
    {
        main_form->cBox_Mute->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::AddRadio()
{
    if(form_Radio == NULL)
    {
        form_Radio = new form_addRadio;
        form_Radio->show();
        connect(form_Radio, SIGNAL(destroyed()), SLOT(ClearFormAddRadio()));
        connect(form_Radio, SIGNAL(send_pushOk(QString,QString)), this, SLOT(AddRadioToPlayList(QString,QString)));
    }
    else
    {
        if(!form_Radio->isActiveWindow())
        {
            form_Radio->activateWindow();
        }
    }
}

void MainWindow::AddRadioToPlayList(QString url, QString nameRadio)
{
    qDebug() << url;
    qDebug() << nameRadio;
    int i = 1;
    while(trackName.contains(nameRadio))
    {
        nameRadio = QString("My radio %2").arg(i);
        i++;
    }
    trackName.append(nameRadio);
    trackTime.insert(url, -1);
    trackPath.insert(nameRadio, url);
    refreshList();
}

void MainWindow::ClearFormAddRadio()
{
    qDebug() << "Erase form_addRadio resources.";
    disconnect(form_Radio, SIGNAL(destroyed()),this, SLOT(ClearFormAddRadio()));
    disconnect(form_Radio, SIGNAL(send_pushOk(QString,QString)), this, SLOT(AddRadioToPlayList(QString,QString)));
    form_Radio = NULL;
}
