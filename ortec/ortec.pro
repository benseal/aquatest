#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T22:11:50
#
#-------------------------------------------------

QT       += core gui axcontainer

TYPELIBS = $$system(dumpcpp -getfile {41CCC090-1ED5-11D3-A1B1-002078147A97})

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ortec
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logdialog.cpp \
    getdatathread.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    logdialog.h \
    getdatathread.h

FORMS    += mainwindow.ui \
    logdialog.ui

INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10240.0/ucrt"
LIBS += -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10240.0\ucrt\x86"

RESOURCES += \
    resource.qrc
