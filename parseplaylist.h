#ifndef PARSEPLAYLIST_H
#define PARSEPLAYLIST_H

#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QList>
#include <QMultiMap>
#include <QDebug>
#include <string>
#include <sstream>

class ParsePlayList
{
public:
    ParsePlayList();
    ~ParsePlayList();

    bool StartParse(QString pathToPlayList);
    QList<QString> GetTrackName();
    QMultiMap<QString, QString> GetTrackPath();
    QMultiMap<QString, int> GetTrackTime();
    QStringList getPathToTrack();

private:
    QStringList pathToTrack;
    QList<QString> listTrackName;
    QMultiMap<QString, QString> listTrackPath;
    QMultiMap<QString, int> listTrackTime;
    QString title;
    QString body;
    void readTime(int *index, QByteArray &arr);
    void readName(int *index, QByteArray &arr, int trackLenght); //trackLenght нужен ждя занесения в карту длинны соответствующей данному треку
    void readPath(int *index, QByteArray &arr, QString trackName);//trackName нужен для занаесения в карту пути до данного трека

    void checkInfo(QString str, int *index, QByteArray &arr);
};

#endif // PARSEPLAYLIST_H
