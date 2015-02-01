#ifndef TESSSTARTER_H
#define TESSSTARTER_H

#include <QObject>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include "imagecrop.h"
#include "trainer.h"
#include "translator.h"

class TessStarter : public QObject
{
    Q_OBJECT
public:
    explicit TessStarter(QObject *parent = 0);

signals:

public slots:

private:
    QAction *restoreImageCropAction;
    QAction *minimizeImageCropAction;

    QAction *restoreTranslatorAction;
    QAction *minimizeTranslatorAction;

    QAction *restoreAction;
    QAction *quitAction;
    QAction *trainerAction;
    QAction *cropAction;
    QAction *historyAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
};

#endif // TESSSTARTER_H
