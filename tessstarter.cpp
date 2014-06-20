#include "tessstarter.h"

TessStarter::TessStarter(QObject *parent) :
    QObject(parent)
{
    trayIcon = new QSystemTrayIcon(this);

    // ----------------------------------------------
    ImageCrop *w = new ImageCrop();
    w->show();

    minimizeImageCropAction = new QAction(tr("Mi&nimize Crapper"), w);
    connect(minimizeImageCropAction, SIGNAL(triggered()), w, SLOT(hide()));

    restoreImageCropAction = new QAction(tr("Restore Crapper"), w);
    connect(restoreImageCropAction, SIGNAL(triggered()), w, SLOT(showNormal()));


    // ----------------------------------------------
    Translator *translator = new Translator();
    restoreTranslatorAction = new QAction(tr("Zeige Translator"), translator);
    connect(restoreTranslatorAction, SIGNAL(triggered()), translator, SLOT(showNormal()));

    minimizeTranslatorAction = new QAction(tr("Minimiere Translator"), translator);
    connect(minimizeTranslatorAction, SIGNAL(triggered()), translator, SLOT(hide()));

    // ----------------------------------------------
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));


    // TrayIcon--------------------------------------

    trayIconMenu = new QMenu(w);

    trayIconMenu->addAction(restoreImageCropAction);
    trayIconMenu->addAction(minimizeImageCropAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(restoreTranslatorAction);
    trayIconMenu->addAction(minimizeTranslatorAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon->setContextMenu(trayIconMenu);


    trayIcon->setVisible(true);
    QIcon icon = QIcon("D:/MyQT_Project/TessTranslator/images/heart.png");
    trayIcon->setIcon(icon);
    translator->setWindowIcon(icon);

    trayIcon->setToolTip("TessTranslator");

    // Add references--------------------------------
    translator->setTrayIcon(trayIcon);
    w->setTranslator(translator);
}
