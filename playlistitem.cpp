#include "playlistitem.h"
#include "ui_playlistitem.h"

PlayListItem::PlayListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayListItem)
{
    ui->setupUi(this);
}

PlayListItem::~PlayListItem()
{
    delete ui;
}
