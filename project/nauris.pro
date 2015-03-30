#-------------------------------------------------
#
# Project created by QtCreator 2015-03-28T11:29:54
#
#-------------------------------------------------

QT       += core gui
QT       += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nauris
TEMPLATE = app
#DESTDIR = ../build


SOURCES += main.cpp\
        mainwindow.cpp \
    browsertab.cpp

HEADERS  += mainwindow.h \
    browsertab.h

FORMS    += mainwindow.ui \
    browsertab.ui
