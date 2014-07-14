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
    Form(QWidget *parent, QString Title, QString Autor, QString Album, QString Genre, int Year, QString NumTrack, int Duration, int Bitrate, int Size );
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
