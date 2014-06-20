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
    qlabelmousetracking.cpp \
    bookdelegate.cpp \
    trainer.cpp \
    tessstarter.cpp \
    imagecrop.cpp \
    translator.cpp

HEADERS  += \
    myqlabelcenter.h \
    qlabelmousetracking.h \
    myqlabelhandler.h \
    bookdelegate.h \
    trainer.h \
    tessstarter.h \
    imagecrop.h \
    translatator.h

FORMS    += \
    actionform.ui \
    trainer.ui \
    imagecrop.ui \
    translator.ui

RESOURCES += \
    systray.qrc
