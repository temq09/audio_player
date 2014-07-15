#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QString>

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
         int size,
         int freq,
         QString typeTrack);
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
