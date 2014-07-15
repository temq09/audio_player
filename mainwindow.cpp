#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

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
    connect(main_form->btn_OpenFile, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(main_form->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(getSelectedIndex(QModelIndex)));
    connect(main_form->btn_Play, SIGNAL(clicked()), this, SLOT(play()));
    connect(main_form->btn_Pause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(main_form->btn_Stop, SIGNAL(clicked()), this, SLOT(stop()));
    connect(main_form->btn_Next, SIGNAL(clicked()), this, SLOT(next()));
    connect(main_form->btn_Previous, SIGNAL(clicked()), this, SLOT(previous()));
    connect(main_form->sb_volume, SIGNAL(valueChanged(int)), core, SLOT(volumeChange(int)));
    connect(main_form->sb_volume, SIGNAL(valueChanged(int)), this, SLOT(checkMute()));
    connect(core, SIGNAL(switchTrack()), this, SLOT(next()));
    connect(main_form->cb_device, SIGNAL(activated(int)), core, SLOT(changeDevice(int)));
    connect(main_form->btn_OpenPlayList, SIGNAL(clicked()), this, SLOT(openPlayList()));
    connect(core, SIGNAL(switchTrack()), this, SLOT(next()));
    connect(main_form->btn_SavePlayList, SIGNAL(clicked()), this, SLOT(savePlayList()));
    connect(this, SIGNAL(sliderChangeWithName(QString,int)), core, SLOT(changeParametrEqalizer(QString,int)));
    connect(main_form->cBox_Mute, SIGNAL(toggled(bool)), this, SLOT(mute(bool)));
    connect(main_form->btn_AddRadio, SIGNAL(clicked()), this, SLOT(addRadio()));
    //connect(main_form->slider_87, SIGNAL, core, SLOT(ChangeParametrEqalizer(int)));
    main_form->listView->setContextMenuPolicy(Qt::ActionsContextMenu);
    act_Info = new QAction("Информация о файле", main_form->listView);
    act_deleteFailFromPlayList = new QAction("Удалить файл из плейлиста", main_form->listView);
    act_deleteFailFromDisk = new QAction("Удалить файл с диска", main_form->listView);


    connect(act_Info, SIGNAL(triggered()),this, SLOT(info()));
    connect(act_deleteFailFromPlayList, SIGNAL(triggered()), this, SLOT(deleteFailFromPlayList()));
    connect(act_deleteFailFromDisk, SIGNAL(triggered()), this, SLOT(deleteFailFromDisk()));
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

void MainWindow::openFile()
{
    QStringList file_list = QFileDialog::getOpenFileNames(this,
                                                          "Открыть файлы",
                                                          "D:\\",
                                                          "Audio (*.mp3 *.raw *.waw);;All files (*.*)");

    qDebug() << "Парсим";
    parseFileList(file_list);
    qDebug() << "Обновляем";
    refreshList();
}

void MainWindow::parseFileList(QStringList &file_list)
{
    QStringList::const_iterator constIterator;
    QElapsedTimer timer;
    timer.start();
    for ( constIterator = file_list.constBegin(); constIterator != file_list.constEnd(); constIterator++)
    {
        //qDebug() << "открываем новый файл";

        ReaderTag *reader = ReaderTagCreator::createReaderTag(QString((*constIterator).toLocal8Bit()));
        if(reader != 0)
        {
            TagInfo tag = reader->getTag();

            trackName.append(tag.title);
            trackPath.insert(tag.title, (*constIterator).toLocal8Bit().constData());
            trackTime.insert(tag.title, tag.length);
        }
    }
    qDebug() << timer.nsecsElapsed();
}

void MainWindow::openPlayList()
{
    QString playList = QFileDialog::getOpenFileName(this,
                                                        "Открыть плейлист",
                                                        "D:\\",
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

void MainWindow::getSelectedIndex(QModelIndex index)
{
    qDebug() << index.row();
    /*QString path = trackPath.value(trackName.at(index.row()));
    qDebug() << path;
    StartPlay(path);*/
    choosePlay(index.row());
    currentPlayTrack = index.row();
}

void MainWindow::startPlay(QString path)
{
    core->playTrack(path);
}

void MainWindow::startPlayRadio(QString path)
{
    core->playRadio(path);
}

void MainWindow::play()
{
    int index = -1;
    index = main_form->listView->currentIndex().row();
    if(index != -1)
    {
        choosePlay(index);
    }
}

void MainWindow::pause()
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
    core->pauseTrack();
}

void MainWindow::stop()
{
    core->stopTrack();
}

void MainWindow::next()
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
        choosePlay(index);
        changeFocusToNextTrack(index);
    }
}

void MainWindow::previous()
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
        choosePlay(index);
        changeFocusToNextTrack(index);
    }
}

void MainWindow::choosePlay(int index)
{
    QString path = trackPath.value(trackName.at(index));
    currentPlayTrack = index;
    if(trackTime.value(trackName.at(index)) == -1)
    {
        startPlayRadio(path);
    }
    else if (trackTime.value(trackName.at(index)) > 0)
    {
        startPlay(path);
    }
}

void MainWindow::changeFocusToNextTrack(int row)
{
    main_form->listView->selectionModel()->select(model.index(row, 0), QItemSelectionModel::ClearAndSelect);
}

void MainWindow::savePlayList()
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

void MainWindow::deleteFailFromPlayList()
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

void MainWindow::deleteFailFromDisk()
{
    qDebug() << "fdfsfddddd";
}

void MainWindow::info()
{
    int index = -1;
    index = main_form->listView->currentIndex().row();
    if (index != -1)
    {
        QString artist = "Неизвестен";
        QString title = "Нет названия";
        QString album = "Неизвестен";
        QString genre = "Неизвестен";
        QString typeTrack = "Неизвестен";
        int year = 0;
        QString numTrack = 0;
        int lenght = 0;
        int bitrate = 0;
        int size = 0;
        int freq = 0;
        QString PathToFile = trackPath.value(trackName.at(index));
        ReaderTag *reader = ReaderTagCreator::createReaderTag(PathToFile);
        TagInfo tags = reader->getTag();

        artist = tags.artist;
        album = tags.album;
        genre = tags.genre;
        title = tags.title;
        year = tags.year;
        numTrack = tags.trackNum;
        lenght = tags.length;
        bitrate = tags.beatRate / 1000;
        freq = tags.frequency / 1000;
        typeTrack = tags.trackType;
        form_info = new Form(this, title, artist, album, genre, year, numTrack, lenght, bitrate, size, freq, typeTrack );
        form_info->setWindowFlags(Qt::Window);
        form_info->show();
        connect(form_info, SIGNAL(destroyed()), this, SLOT(clearFormInfo()));

    }
}

void MainWindow::clearFormInfo()
{
    delete form_info;
    disconnect(form_info, SIGNAL(destroyed()), this, SLOT(clearFormInfo()));
}

void MainWindow::mute(bool state)
{
    if(state == true)
    {
        qDebug() << "Выключаем звук";
        core->volumeChange(0);
    }
    else if(state == false)
    {
        qDebug() << "Включаем звук";
        core->volumeChange(main_form->sb_volume->value());
    }
}

void MainWindow::checkMute()
{
    if(main_form->cBox_Mute->isChecked())
    {
        main_form->cBox_Mute->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::addRadio()
{
    if(form_Radio == NULL)
    {
        form_Radio = new form_addRadio;
        form_Radio->show();
        connect(form_Radio, SIGNAL(destroyed()), SLOT(clearFormAddRadio()));
        connect(form_Radio, SIGNAL(send_pushOk(QString,QString)), this, SLOT(addRadioToPlayList(QString,QString)));
    }
    else
    {
        if(!form_Radio->isActiveWindow())
        {
            form_Radio->activateWindow();
        }
    }
}

void MainWindow::addRadioToPlayList(QString url, QString nameRadio)
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

void MainWindow::clearFormAddRadio()
{
    qDebug() << "Erase form_addRadio resources.";
    disconnect(form_Radio, SIGNAL(destroyed()),this, SLOT(clearFormAddRadio()));
    disconnect(form_Radio, SIGNAL(send_pushOk(QString,QString)), this, SLOT(addRadioToPlayList(QString,QString)));
    form_Radio = NULL;
}
