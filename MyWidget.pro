#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T09:19:37
#
#-------------------------------------------------

QT       += core gui sql
QT       += widgets
QT       += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qlabelmousetracking.cpp \
    actionform.cpp \
    translation.cpp \
    bookdelegate.cpp

HEADERS  += widget.h \
    myqlabelcenter.h \
    qlabelmousetracking.h \
    myqlabelhandler.h \
    actionform.h \
    translation.h \
    bookdelegate.h

FORMS    += widget.ui \
    actionform.ui \
    translation.ui

RESOURCES += \
    systray.qrc
