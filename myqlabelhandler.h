#ifndef MYQLABELHANDLER_H
#define MYQLABELHANDLER_H
#include <QLabel>
#include <QVector>

class MyQLabelHandler
{
public:
    MyQLabelHandler();
    static void setQLabel(QLabel *label);

private:

    QVector<QLabel> vecLabels;
};

#endif // MYQLABELHANDLER_H
