#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::Form(QWidget *parent, QString Title, QString Autor, QString Album, QString Genre, int Year, int NumTrack, int Duration, int Bitrate, int Size) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->lb_setTitle->setText(Title);
    ui->lb_setAutor->setText(Autor);
    ui->lb_setAlbum->setText(Album);
    ui->lb_setGenre->setText(Genre);
    ui->lb_setYear->setText(QString::number(Year));
    ui->lb_setNumTrack->setText(QString::number(NumTrack));
    ui->lb_setDuration->setText(QString::number(Duration));
    ui->lb_setQuality->setText((QString("%1 kbps").arg(QString::number(Bitrate))));
    ui->lb_setSize->setText(QString("%1 Mb.").arg(QString::number(Size/100000)));
}

Form::~Form()
{
    delete ui;
}
