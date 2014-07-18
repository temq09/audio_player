#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <QWidget>

#include "readertag.h"

namespace Ui {
class PlayListItem;
}

class PlayListItem : public QWidget
{
    Q_OBJECT

public:
    explicit PlayListItem(QWidget *parent = 0);
    PlayListItem(QWidget *parent, TagInfo tags);
    ~PlayListItem();
    TagInfo getTags();

private:
    Ui::PlayListItem *ui;
    TagInfo _tags;
};

#endif // PLAYLISTITEM_H
