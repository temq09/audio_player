#-------------------------------------------------
#
# Project created by QtCreator 2013-09-24T17:35:52
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = audio_player
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    audioplayer_core.cpp \
    audiocore.cpp

HEADERS  += mainwindow.h \
    audioplayer_core.h \
    audiocore.h

FORMS    += mainwindow.ui
