#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::Form(QWidget *parent,
           QString title,
           QString autor,
           QString album,
           QString genre,
           int year,
           QString numTrack,
           int duration,
           int bitrate,
           quint64 size,
           int freq,
           QString typeTrack, QString pathToFile) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->lb_setTitle->setText(title);
    ui->lb_setAutor->setText(autor);
    ui->lb_setAlbum->setText(album);
    ui->lb_setGenre->setText(genre);
    ui->lb_setYear->setText(QString::number(year));
    ui->lb_setNumTrack->setText(numTrack);
    ui->lb_setDuration->setText(QString::number(duration));
    ui->lb_setQuality->setText((QString("%1 kbps; %2 kHz").arg(QString::number(bitrate)).arg(QString::number(freq))));
    ui->lb_setSize->setText(QString("%1 Мбайт.").arg(QString::number((double)size/ONE_MEGABYTE)));
    ui->lb_setFormat->setText(typeTrack);
    ui->lb_pathToFile->setText(pathToFile);
}

Form::~Form()
{
    delete ui;
}
