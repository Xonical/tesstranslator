#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T09:19:37
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qlabelmousetracking.cpp

HEADERS  += widget.h \
    myqlabelcenter.h \
    qlabelmousetracking.h \
    myqlabelhandler.h

FORMS    += widget.ui
