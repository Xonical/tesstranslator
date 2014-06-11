#include "myqlabelhandler.h"
#include <QVector>

MyQLabelHandler::MyQLabelHandler()
{

}

void MyQLabelHandler::setQLabel(QLabel *label)
{
    // this->vecLabels.append(label);
}


class MyQLabelReferences
{
public:
    MyQLabelReferences();

private:

    QVector<QLabel> vecLabels;
};

MyQLabelReferences::MyQLabelReferences()
{

}
