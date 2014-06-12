#include "qlabelmousetracking.h"
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include <QString>
#include <QWidget>

QLabelMouseTracking::QLabelMouseTracking(QWidget *parent) :
    QLabel(parent)
{
    this->setMouseTracking(true);
}

void QLabelMouseTracking::mouseMoveEvent(QMouseEvent *ev)
{
    /*
    int x = 0; int y =0; int width = 1280; int height = 1024;
    bool toZoom = true;
    while(toZoom){

               if(x!= 512){
                   x++;
               }
               if(y= 20){
                   y++;
               }

               if(width!= 629){
                   width--;
               }
               if(height != 327){
                   height--;
               }
              this->setGeometry(x,y,width,height);
               if(x==512 && y == 20 &&
                  width == 629 && height == 327){
                   toZoom =false;
               }
    }
*/




    this->x = ev->x();
    this->y = ev->y();

    //QString *curObj = this->objectName();
    if (this->objectName() == "lblCenter"){
        setCursor( Qt::OpenHandCursor);
    }else if(this->objectName() == "lblLeft"){
        setCursor( Qt::SizeHorCursor );
        if (ev->buttons() == Qt::LeftButton ){
            this->expandToLeft(ev,this);
        }
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
       // qDebug() << "x " + QString::number(rect.x() + ev->x()) + " y " + QString::number(rect.y());
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
    QWidget *mainWidget = this->parentWidget();
    //the Global-X Position add the width and subtract the position
    // that was mapped from the border to the parent
    rightBorderX  = ev->globalX() + mainWidget->geometry().width() -ev->x();
    qDebug() << "aa-Def: " << this->rightBorderX;


    //QPoint temp(topRight,0);
    //buttonPressedGlobalPos = ev->globalPos();
    this->oldGlobalPos = ev->globalPos();
    int oldX = this->oldGlobalPos.x();
    oldX -6;
    this->oldGlobalPos.setX(oldX);
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

void QLabelMouseTracking::expandToLeft(QMouseEvent *ev, QLabel *label)
{
    qDebug() << "ev->globalX(): " << ev->globalX();
    qDebug() << "ev->XY: "<< ev->x() << " " << ev->y();


    if(ev->x()<-1){
        //return;
    }



    QWidget *mainWidget = this->parentWidget();
    QPoint globalPoint = label->mapToGlobal( ev->pos() );
    //qDebug() << "ev->XY: "<< ev->x() << " " << ev->y();
  /*    qDebug() << "expand to left: x: " <<globalPoint.x()<< " y: " << globalPoint.y();

    qDebug() << "ev->global XY: "<< ev->globalX() << " " << ev->globalY();
*/
    //this->leftButtonPressedRightX;
    // Now add the difference to the geometry
    //int newWeight = mainWidget->geometry().width();// + ( ev->x()*-1);

    int newWeight = 0;
    // The user expand to left, not to the right
    //if(ev->globalX() < this->rightBorderX - mainWidget->geometry().width()){
        //int growRight = (ev->globalX() - this->oldGlobalPos.x()) *-1;
        qDebug() << "GR: " ;

        //Wird negiert, da nach Bewegung außerhalb negative Werte auslößt
        int toGrowToRight = (ev->x()*-1);
        int newX = ev->globalX();
        int newSize = mainWidget->width() + toGrowToRight;

        int y = mainWidget->geometry().y();
        int height = mainWidget->geometry().height();

        if (this->rightBorderX == newSize){
            mainWidget->setGeometry(newX,y,newSize,height);
        }
        qDebug() << "this->rightBorderX: " << this->rightBorderX;
        qDebug() << "newSize: " << newSize;
        //newWeight = mainWidget->geometry().width() + growRight;


        mainWidget->setGeometry(ev->globalX(),y,newSize,height);
    //}
    this->oldGlobalPos = ev->globalPos();


    /* Works for the central widget
    QWidget *mainWidget = this->parentWidget();
    QPoint globalPoint = label->mapToGlobal( ev->pos() );
    qDebug() << "expand to left: x: " <<globalPoint.x()<< " y: " << globalPoint.y();



    //mainWidget->move();
    // Now add the difference to the geometry
    int newWeight = mainWidget->geometry().width();// + ( ev->x()*-1);
    int y = mainWidget->geometry().y();
    int height = mainWidget->geometry().height();
    mainWidget->setGeometry(globalPoint.x(),y,newWeight,height);


      */

}
