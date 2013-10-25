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
    form_addradio.cpp

HEADERS  += mainwindow.h \
    audiocore.h \
    parseplaylist.h \
    modernslider.h \
    form.h \
    form_addradio.h

FORMS    += mainwindow.ui \
    form.ui \
    form_addradio.ui

DEFINES += NOMINMAX

#if minGw
#INCLUDEPATH += "D:\\work\\taglib\\include"
#LIBS += -L"D:\\Qt_app\\audio_player\\src\\libtag"
#LIBS += -llibtag

#if MSVC 2012
INCLUDEPATH += "D:\\work\\taglib_msvc2012\\include"
LIBS += -L"D:\\Qt_app\\audio_player\\src\\libtag_msvc2012"
LIBS += -ltag

LIBS += -L"D:\\Qt_app\\audio_player\\src\\bass"
LIBS += -lbass
