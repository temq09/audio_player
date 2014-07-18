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
    audiocore.cpp \
    parseplaylist.cpp \
    modernslider.cpp \
    form.cpp \
    form_addradio.cpp \
    readertag.cpp \
    readerid3v1tag.cpp \
    readerid3v2tag.cpp \
    readertagcreator.cpp \
    playlistitem.cpp

HEADERS  += mainwindow.h \
    audiocore.h \
    parseplaylist.h \
    modernslider.h \
    form.h \
    form_addradio.h \
    readertag.h \
    readerid3v1tag.h \
    readerid3v2tag.h \
    readertagcreator.h \
    playlistitem.h

FORMS    += mainwindow.ui \
    form.ui \
    form_addradio.ui \
    playlistitem.ui

#if MSVC 2012
INCLUDEPATH += "$$PWD\\src\\bass\\bass_include"

LIBS += -L"$$PWD\\src\\bass\\bass_lib\\"

LIBS += -lbass

CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

CONFIG(release, debug|release):QMAKE_CXXFLAGS += -O2

