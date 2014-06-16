/*
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
*/

#include "translation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Translation w;
    //w.setUrl("https://translate.google.de/#en/de/eaten");
    w.show();

    return a.exec();
}

