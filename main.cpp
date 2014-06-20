#include <QApplication>


#include <QMessageBox>
#include "tessstarter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    new TessStarter();

    return a.exec();
}
