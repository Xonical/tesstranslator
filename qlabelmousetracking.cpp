#include "qlabelmousetracking.h"
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include <QString>

QLabelMouseTracking::QLabelMouseTracking(QWidget *parent) :
    QLabel(parent)
{
    this->setMouseTracking(true);
}

void QLabelMouseTracking::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();

    //QString *curObj = this->objectName();
    if (this->objectName() == "lblCenter"){
        setCursor( Qt::OpenHandCursor);
    }else if(this->objectName() == "lblLeft"){
        setCursor( Qt::SizeHorCursor );
    }else if(this->objectName() == "lblRight"){
        setCursor( Qt::SizeHorCursor );
    }else if(this->objectName() == "lblTop"){
        setCursor( Qt::SizeVerCursor );
    }else if(this->objectName() == "lblBottom"){
        setCursor( Qt::SizeVerCursor );
    }else if(this->objectName() == "lblTopLeft"){
        setCursor( Qt::SizeFDiagCursor );
    }else if(this->objectName() == "lblTopRight"){
        setCursor( Qt::SizeBDiagCursor );
    }else if(this->objectName() == "lblBottomLeft"){
        setCursor( Qt::SizeBDiagCursor);
    }else if(this->objectName() == "lblBottomRight"){
        setCursor( Qt::SizeFDiagCursor );
    }




    if(ev->buttons() == Qt::LeftButton &&
            this->objectName() == "lblLeft"

    ){
//qDebug() << "x " + QString::number(ev->x()) + " y " + QString::number(ev->y());
QRect rect =  this->geometry();
//Master
        this->move(ev->x(),0);
        //this->setGeometry(rect.x() + ev->x(),rect.y(),rect.width(),rect.height());
        qDebug() << "x " + QString::number(rect.x() + ev->x()) + " y " + QString::number(rect.y());
    }





    QPoint point2;
    QPoint point = this->mapToGlobal(point2);
    //qDebug() << "x " + QString::number(point.x()) + " y " + QString::number(point.y());
    //qDebug() << "x " + QString::number(ev->x()) + " y " + QString::number(ev->y());


    if (this->objectName() != "lblCenter"){
        this->setStyleSheet("background-color: rgba(139, 169, 119, 0.7)");
    }




}

void QLabelMouseTracking::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void QLabelMouseTracking::leaveEvent(QEvent *ev)
{
    if (this->objectName() != "lblCenter"){
        this->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    }

    emit Mouse_Left();
}

void QLabelMouseTracking::setCentralQLabel(QLabel *label)
{
    this->centralQLabel= label;
}
