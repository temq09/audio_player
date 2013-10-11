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
    audiocore.cpp \
    parseplaylist.cpp \
    modernslider.cpp

HEADERS  += mainwindow.h \
    audioplayer_core.h \
    audiocore.h \
    parseplaylist.h \
    modernslider.h

FORMS    += mainwindow.ui

#LIBS += -L../lib
#LIBS += $$PWD/../Source/lib/bass.lib
#LIBS += -lbass

INCLUDEPATH += "D:\\work\\taglib\\include"

LIBS += -L"D:\work\taglib\bin"
LIBS += -llibtag
LIBS += -L"C:\tmp"
LIBS += -lbass
