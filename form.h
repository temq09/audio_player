#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QString>

#define ONE_MEGABYTE 1000000

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    Form(QWidget *parent,
         QString Title,
         QString Autor,
         QString album,
         QString genre,
         int year,
         QString numTrack,
         int duration,
         int bitrate,
         quint64 size,
         int freq,
         QString typeTrack,
         QString pathToFile);
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
