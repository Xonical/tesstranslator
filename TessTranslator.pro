#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T09:19:37
#
#-------------------------------------------------

QT       += core gui sql
QT       += widgets
QT       += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TessTranslator
TEMPLATE = app


SOURCES += main.cpp\
    qlabelmousetracking.cpp \
    trainer.cpp \
    tessstarter.cpp \
    imagecrop.cpp \
    translator.cpp \
    historydelegate.cpp \
    mainwindow.cpp \
    languagehelper.cpp \
    databasebuilder.cpp

HEADERS  += \
    myqlabelcenter.h \
    qlabelmousetracking.h \
    myqlabelhandler.h \
    trainer.h \
    tessstarter.h \
    imagecrop.h \
    translator.h \
    historydelegate.h \
    mainwindow.h \
    languagehelper.h \
    databasebuilder.h

FORMS    += \
    trainer.ui \
    imagecrop.ui \
    translator.ui \
    mainwindow.ui

RESOURCES += \
    systray.qrc
