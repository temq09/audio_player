#include "playlistitem.h"
#include "ui_playlistitem.h"

PlayListItem::PlayListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayListItem)
{
    ui->setupUi(this);
}

PlayListItem::PlayListItem(QWidget *parent, TagInfo tags) :
    QWidget(parent),
    ui(new Ui::PlayListItem),
    _tags(tags)
{
    ui->setupUi(this);
    ui->lb_trackName->setText(QString("%1 - %2").arg(tags.artist).arg(tags.title));
    ui->lb_beatrate->setText(QString("%1 kbps").arg(tags.beatRate / 1000));
    ui->lb_freq->setText(QString("%1 kHz").arg(tags.frequency / 1000));
    ui->lb_type->setText(tags.trackType);
    ui->lb_size->setText(QString("%1 MB").arg((double)tags.size / 1000000));
    ui->lb_lenght->setText(QString("%1:%2").arg(tags.length / 60).arg(tags.length % 60));
}

PlayListItem::~PlayListItem()
{
    delete ui;
}

TagInfo PlayListItem::getTags()
{
    return _tags;
}
