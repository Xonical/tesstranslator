#include "widget.h"
#include "ui_widget.h"
#include <QTimer>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
ui->setupUi(this);
    ui->lblLeft->setCentralQLabel(ui->lblCenter);
    ui->horizontalLayout->setContentsMargins(0,0,0,0);

     
    //qDebug() << "!!! " << My::getCentralLabel().objectName();


    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0); // Create TopLevel-Widget
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_PaintOnScreen); // as pointed by Caveman (thanks!)


    ui->lblBottom->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblBottomLeft->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblBottomRight->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    //ui->lblCenter->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblLeft->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblRight->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblTop->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblTopLeft->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblTopRight->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");


    //629, 327

    //this->move(512,20);
    int x = 0; int y =0; int width = 1280; int height = 1024;
    this->setGeometry(x,y,width,height);


    QTimer::singleShot(1000, this, SLOT(doLater()));





/*

*/


}

Widget::~Widget()
{
    delete ui;
}

void Widget::doLater()
{
    //this->setGeometry(512,20,639,327);
    //ui->lblCenter->setText("Bllaaaaaa");

    int x = 0; int y =0; int width = 1280; int height = 1024;
    bool toZoom = true;
    while(toZoom){

               if(x < 512){
                   x++;
                   qDebug()<<"Finish 1";
               }
               if(y < 20){
                   y++;
                   qDebug()<<"Finish 2";
               }

               if(width > 629){
                   width--;
                   qDebug()<<"Finish 3";
               }
               if(height > 327){
                   height--;
                   qDebug()<<"Finish 4";
               }
              this->setGeometry(x,y,width,height);
               if(x==512 && y == 20 &&
                  width == 629 && height == 327){
                   toZoom =false;
                   qDebug()<<"Finish 5";
               }
    }

}
