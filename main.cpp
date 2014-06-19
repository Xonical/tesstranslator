/*

#include <QApplication>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QMessageBox>
#include "widget.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(systray);

    QApplication a(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        return 1;
    }

    QApplication::setQuitOnLastWindowClosed(false);


    Widget w;
    w.show();

    return a.exec();
}
*/



#include <QApplication>
#ifndef QT_NO_SYSTEMTRAYICON


#include <QMessageBox>

#include "translation.h"



int main(int argc, char *argv[])
{

        Q_INIT_RESOURCE(systray);

    QApplication a(argc, argv);
    a.setStyleSheet("QSplitter::handle { background-color: yellow }");

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        return 1;
    }

    QApplication::setQuitOnLastWindowClosed(false);
    Translation w;

    w.show();
    //w.setUrl("https://translate.google.de/#en/de/eaten");
    //w.setTextToTranslate("eaten");
    return a.exec();
}



#else

#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text("QSystemTrayIcon is not supported on this platform");

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);

    label->show();
    qDebug() << text;

    app.exec();
}

#endif
