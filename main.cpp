#include <QApplication>


#include <QMessageBox>
#include "tessstarter.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //new TessStarter();
    new MainWindow();

    return a.exec();
}
