#include "qlabelmousetracking.h"
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>

QLabelMouseTracking::QLabelMouseTracking(QWidget *parent) :
    QLabel(parent)
{
    this->setMouseTracking(true);
}

void QLabelMouseTracking::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    //QDesktopWidget *desktopWidget = QApplication::desktop();

    QPoint point2;
    QPoint point = this->mapToGlobal(point2);
    qDebug() << "x " + QString::number(point.x()) + " y " + QString::number(point.y());
    //qDebug() << "x " + QString::number(ev->x()) + " y " + QString::number(ev->y());
    this->setStyleSheet("background-color: rgba(139, 169, 119, 0.7)");
}

void QLabelMouseTracking::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void QLabelMouseTracking::leaveEvent(QEvent *ev)
{
     this->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
     emit Mouse_Left();
}
