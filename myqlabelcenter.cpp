#include "myqlabelcenter.h"
#include <QRect>
#include <QObject>
#include<QWidget>
#include<QFrame>
#include<QDebug>
#include <QLabel>
#include <QPixmap>
#include <QPainter>

MyQLabelCenter::MyQLabelCenter(QWidget *parent) :
    QLabel(parent)
{
    QWidget *widget = qobject_cast<QWidget *>(parent);
    this->setText("Subclass");
    qDebug() << "fsdf";
    //QRect rectParent = widget->geometry();
    //QRect rect =  this->geometry();
    //this->setGeometry(rectParent.x(),rectParent.y(),rectParent.width(),rectParent.height());
    //this->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");

}
