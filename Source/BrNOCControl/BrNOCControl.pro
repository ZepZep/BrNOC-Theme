#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T10:51:35
#
#-------------------------------------------------

QT       += core gui
QT       += qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrNOCControl
TEMPLATE = app


SOURCES += main.cpp\
        controlform.cpp \
    timetablemodel.cpp

HEADERS  += controlform.h \
    timetablemodel.h

FORMS    += controlform.ui
