#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_form(new Ui::MainWindow)
{
    main_form->setupUi(this);

    /*
     * setting variables
     */
    currentVolume = 50;
    currentPlayTrack = 0;
    core = new AudioCore(this, currentVolume);
    /*mySlider = new modernSlider(this);
    mySlider->setObjectName("slider 1");
    mySlider->setWindowIconText("asdf");
    main_form->horizontalLayout_4->addWidget(mySlider);*/

    /*
     * settings form
     */
    //main_form->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    main_form->sb_volume->setValue(currentVolume);
    foreach (const QAudioDeviceInfo &device, QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)) {
        main_form->cb_device->addItem(device.deviceName(), qVariantFromValue(device));
    }
    //main_form->listView->setDragDropMode(QAbstractItemView::DragDrop);

    /*
     * connect block
     */
    //ConnectedSlyderSignalsAndSlots();
    connect(main_form->btn_OpenFile, SIGNAL(clicked()), this, SLOT(openFile()));
    //connect(main_form->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(getSelectedIndex(QModelIndex)));
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
    main_form->lw_playlist->setContextMenuPolicy(Qt::ActionsContextMenu);
    act_Info = new QAction("Информация о файле", main_form->lw_playlist);
    act_deleteFailFromPlayList = new QAction("Удалить файл из плейлиста", main_form->lw_playlist);
    act_deleteFailFromDisk = new QAction("Удалить файл с диска", main_form->lw_playlist);


    connect(act_Info, SIGNAL(triggered()),this, SLOT(info()));
    connect(act_deleteFailFromPlayList, SIGNAL(triggered()), this, SLOT(deleteFailFromPlayList()));
    connect(act_deleteFailFromDisk, SIGNAL(triggered()), this, SLOT(deleteFailFromDisk()));
    main_form->lw_playlist->addAction(act_Info);
    main_form->lw_playlist->addAction(act_deleteFailFromPlayList);
    main_form->lw_playlist->addAction(act_deleteFailFromDisk);
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
}

void MainWindow::parseFileList(QStringList &file_list)
{
    QStringList::const_iterator constIterator;
    QElapsedTimer timer;
    timer.start();
    for ( constIterator = file_list.constBegin(); constIterator != file_list.constEnd(); constIterator++)
    {
        //qDebug() << "открываем новый файл";
        QString tmp = (*constIterator).left(8);
        if(tmp.contains("http://"))
        {
            TagInfo tag;
            tag.length = 0;
            tag.title = (QString)(*constIterator);
            tag.pathToFile = (QString)(*constIterator);
            addItemToPlayList(tag);
        }
        else
        {
            ReaderTag *reader = ReaderTagCreator::createReaderTag(QString(*constIterator));
            if(reader != 0)
            {
                TagInfo tag = reader->getTag();
                //если значение артиста ноль или пустая строка, то добавлять будем по названию файла
                if(tag.title.isEmpty())
                {
                    QString tmpStr = (QString)((*constIterator).unicode());
                    int index = tmpStr.lastIndexOf("\\");
                    if (-1 == index)
                        index = tmpStr.lastIndexOf("/");
                    tag.title = tmpStr.right( tmpStr.length() - index - 1);
                }
                addItemToPlayList(tag);
            }
            delete reader;
        }
    }
    qDebug() << timer.nsecsElapsed();
}

void MainWindow::addRadio()
{
    form_addRadio *form = new form_addRadio();
    connect(form, SIGNAL(send_pushOk(QString,QString)), this, SLOT(addRadioToPlayList(QString,QString)));
    form->show();
}

void MainWindow::addRadioToPlayList(QString url, QString nameRadio)
{
    qDebug() << url;
    qDebug() << nameRadio;
    //int i = 1;
    /*while(trackName.contains(nameRadio))
    {
        nameRadio = QString("My radio %2").arg(i);
        i++;
    }*/
    TagInfo tagRadio;
    tagRadio.title = nameRadio;
    tagRadio.length = -1;
    tagRadio.pathToFile = url;
    addItemToPlayList(tagRadio);
}

void MainWindow::addItemToPlayList(TagInfo tag)
{
    PlayListItem *item = new PlayListItem(this, tag);
    playList.append(item);
    QListWidgetItem *it = new QListWidgetItem();
    it->setSizeHint(item->size());
    main_form->lw_playlist->addItem(it);
    main_form->lw_playlist->setItemWidget(it, item);
}

void MainWindow::openPlayList()
{
    QString playList = QFileDialog::getOpenFileName(this,
                                                        "Открыть плейлист",
                                                        "D:\\",
                                                        "playlist (*.m3u)");
    if(playList.isEmpty())
        return;
    ParsePlayList* parsePlaylist = new ParsePlayList;

    QStringList playStringList;
    if(parsePlaylist->StartParse(playList))
        playStringList = parsePlaylist->getPathToTrack();
    parseFileList(playStringList);

    delete parsePlaylist;
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
    index = main_form->lw_playlist->currentIndex().row();
    if(index != -1)
    {
        choosePlay(index);
    }
}

void MainWindow::pause()
{
    if(playList.isEmpty())
    {
        qDebug() << "Плей лист пустой, него ставить на паузу";
        return;
    }
    if(playList.at(currentPlayTrack)->getTags().length == -1)
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
        int range = playList.size();
        index = rand()%range;
    }
    else
    {
        index = currentPlayTrack+1;
    }

    if (index != -1)
    {
        if(index > playList.size()-1)
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
    TagInfo tag = playList.at(index)->getTags();
    QString path = tag.pathToFile;
    currentPlayTrack = index;
    if(tag.length == 0)
    {
        startPlayRadio(path);
    }
    else if (tag.length > 0)
    {
        startPlay(path);
    }
}

void MainWindow::changeFocusToNextTrack(int row)
{
    main_form->lw_playlist->selectionModel()->select(model.index(row, 0), QItemSelectionModel::ClearAndSelect);
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
        out.setCodec("UTF8");
        out << title << "\n";
        foreach (PlayListItem *tag, playList)
        {
            out << body << ":" << tag->getTags().length << "," << QString("%1 - %2").arg(tag->getTags().artist).arg(tag->getTags().title)
                   << "\n" << tag->getTags().pathToFile << "\n";
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
    QModelIndexList indexLists = main_form->lw_playlist->selectionModel()->selectedRows();
    int count = 0;
    foreach (QModelIndex index, indexLists) {
        playList.removeAt(index.row() - count);
        delete main_form->lw_playlist->item(index.row() - count);
        count++;
    }
}

void MainWindow::deleteFailFromDisk()
{
    qDebug() << "fdfsfddddd";
}

void MainWindow::info()
{
    int index = -1;
    index = main_form->lw_playlist->currentIndex().row();
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
        TagInfo playListItem = playList.at(index)->getTags();

        QString path = playListItem.pathToFile;
        artist = playListItem.artist;
        album = playListItem.album;
        genre = playListItem.genre;
        title = playListItem.title;
        year = playListItem.year;
        size = playListItem.size;
        numTrack = playListItem.trackNum;
        lenght = playListItem.length;
        bitrate = playListItem.beatRate / 1000;
        freq = playListItem.frequency / 1000;
        typeTrack = playListItem.trackType;
        form_info = new Form(this, title, artist, album, genre, year, numTrack, lenght, bitrate, size, freq, typeTrack, path );
        form_info->setWindowFlags(Qt::Window);
        form_info->show();
        connect(form_info, SIGNAL(destroyed()), this, SLOT(clearFormInfo()));
    }
}

void MainWindow::clearFormInfo()
{
    delete form_info;
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
