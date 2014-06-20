#include "tessstarter.h"

TessStarter::TessStarter(QObject *parent) :
    QObject(parent)
{

    trayIcon = new QSystemTrayIcon(this);


    // -------------Crop-Widget
    ImageCrop *w = new ImageCrop();
    w->show();

    minimizeImageCropAction = new QAction(tr("Mi&nimize Crapper"), w);
    connect(minimizeImageCropAction, SIGNAL(triggered()), w, SLOT(hide()));

    restoreImageCropAction = new QAction(tr("Restore Crapper"), w);
    connect(restoreImageCropAction, SIGNAL(triggered()), w, SLOT(showNormal()));



qDebug() << "STart";

// -------------Translator-Dialog

 Translator *translator = new Translator();
 restoreTranslatorAction = new QAction(tr("Zeige Translator"), translator);
 connect(restoreTranslatorAction, SIGNAL(triggered()), translator, SLOT(showNormal()));

 minimizeTranslatorAction = new QAction(tr("Minimiere Translator"), translator);
 connect(minimizeTranslatorAction, SIGNAL(triggered()), translator, SLOT(hide()));


 quitAction = new QAction(tr("&Quit"), this);
 connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));


// -------------TrayIcon

trayIconMenu = new QMenu(w);

trayIconMenu->addAction(restoreImageCropAction);
trayIconMenu->addAction(minimizeImageCropAction);

trayIconMenu->addAction(restoreTranslatorAction);
trayIconMenu->addAction(minimizeTranslatorAction);

trayIconMenu->addAction(quitAction);


trayIcon->setContextMenu(trayIconMenu);




                   trayIcon->setVisible(true);
                   QIcon icon = QIcon("D:/MyQT_Project/TessTranslator/images/heart.png");
                   trayIcon->setIcon(icon);
//                   //setWindowIcon(icon);

                   trayIcon->setToolTip("TessTranslator");

    //createActions();


    //createTrayIcon();

      // -----Add References
      translator->setTrayIcon(trayIcon);
      w->setTranslator(translator);

}

void TessStarter::createActions()
{
            minimizeImageCropAction = new QAction(tr("Mi&nimize"), this);
            connect(minimizeImageCropAction, SIGNAL(triggered()), this, SLOT(hide()));



//        Trainer *trainer = new Trainer(this);


//        trainerAction = new QAction(tr("&Trainer"), this);
//        connect(trainerAction, SIGNAL(triggered()), trainer, SLOT(exec()));

//        minimizeAction = new QAction(tr("Mi&nimize"), this);
//        connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

//        restoreAction = new QAction(tr("&Restore"), this);
//        connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));


}

void TessStarter::createTrayIcon()
{
//        trayIconMenu = new QMenu(this);
//        trayIconMenu->addAction(trainerAction);
//        trayIconMenu->addAction(minimizeAction);
//        trayIconMenu->addAction(restoreAction);
//        trayIconMenu->addSeparator();
//        trayIconMenu->addAction(quitAction);

//        trayIcon = new QSystemTrayIcon(this);
//        trayIcon->setContextMenu(trayIconMenu);





//        trayIcon->setVisible(true);
//        QIcon icon = QIcon("D:/MyQT_Project/TessTranslator/images/heart.png");
//        trayIcon->setIcon(icon);
//        setWindowIcon(icon);

//        trayIcon->setToolTip("TessTranslator");
}

//void Translation::createActions()
//{
//    Trainer *trainer = new Trainer(this);


//    trainerAction = new QAction(tr("&Trainer"), this);
//    connect(trainerAction, SIGNAL(triggered()), trainer, SLOT(exec()));

//    minimizeAction = new QAction(tr("Mi&nimize"), this);
//    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

//    restoreAction = new QAction(tr("&Restore"), this);
//    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

//    quitAction = new QAction(tr("&Quit"), this);
//    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
//}

//void Translation::createTrayIcon()
//{
//    trayIconMenu = new QMenu(this);
//    trayIconMenu->addAction(trainerAction);
//    trayIconMenu->addAction(minimizeAction);
//    trayIconMenu->addAction(restoreAction);
//    trayIconMenu->addSeparator();
//    trayIconMenu->addAction(quitAction);

//    trayIcon = new QSystemTrayIcon(this);
//    trayIcon->setContextMenu(trayIconMenu);

//    trayIcon->setVisible(true);
//    QIcon icon = QIcon("D:/MyQT_Project/TessTranslator/images/heart.png");
//    trayIcon->setIcon(icon);
//    setWindowIcon(icon);

//    trayIcon->setToolTip("TessTranslator");
//}

//void Translation::createActions()
//{
//    Trainer *trainer = new Trainer(this);


//    trainerAction = new QAction(tr("&Trainer"), this);
//    connect(trainerAction, SIGNAL(triggered()), trainer, SLOT(exec()));

//    minimizeAction = new QAction(tr("Mi&nimize"), this);
//    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

//    restoreAction = new QAction(tr("&Restore"), this);
//    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

//    quitAction = new QAction(tr("&Quit"), this);
//    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
//}

