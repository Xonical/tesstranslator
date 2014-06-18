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
    a.setStyleSheet("QSplitter::handle { background-color: yellow }");
    Translation w;

    w.show();
    //w.setUrl("https://translate.google.de/#en/de/eaten");
    w.setTextToTranslate("eaten");
    return a.exec();
}

