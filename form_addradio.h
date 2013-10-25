#ifndef FORM_ADDRADIO_H
#define FORM_ADDRADIO_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class form_addRadio;
}

class form_addRadio : public QWidget
{
    Q_OBJECT

public:
    explicit form_addRadio(QWidget *parent = 0);
    ~form_addRadio();

public slots:
    void PushOk();
    void PushCancel();

protected:


private:
    Ui::form_addRadio *ui;

signals:
    void send_pushOk(QString url, QString nameRadio);
    void closeEvent(QCloseEvent* e);
    //void send_pushCancel();
};

#endif // FORM_ADDRADIO_H
