#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <QWidget>

namespace Ui {
class PlayListItem;
}

class PlayListItem : public QWidget
{
    Q_OBJECT

public:
    explicit PlayListItem(QWidget *parent = 0);
    ~PlayListItem();

private:
    Ui::PlayListItem *ui;
};

#endif // PLAYLISTITEM_H
