#include "form_addradio.h"
#include "ui_form_addradio.h"

form_addRadio::form_addRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_addRadio)
{
    ui->setupUi(this);
    connect(ui->pb_Ok, SIGNAL(clicked()), SLOT(PushOk()));
    connect(ui->pb_Cansel, SIGNAL(clicked()), SLOT(PushCancel()));
    connect(this, SIGNAL(closeEvent(QCloseEvent*)), this, SLOT(PushCancel()));
}

form_addRadio::~form_addRadio()
{
    qDebug() << "Erase form_radio";
    emit destroyed(this);
    delete ui;
    this->destroy();
}

void form_addRadio::PushOk()
{
    QString url = ui->lE_radioUrl->text().toLocal8Bit().constData();
    QString radioName = ui->lE_radioName->text().toLocal8Bit().constData();

    if(url.isEmpty())
    {
        QMessageBox box;
        box.setText("Введите url!");
        box.exec();
    }
    else
    {
        if(radioName.isEmpty())
        {
            radioName = "My Radio";
        }
        emit send_pushOk(url, radioName);
        this->~form_addRadio();
    }
}

void form_addRadio::PushCancel()
{
    this->~form_addRadio();
   // emit destroyed(this);
}

