#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lblLeft->setCentralQLabel(ui->lblCenter);


     
    //qDebug() << "!!! " << My::getCentralLabel().objectName();

    //setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    //setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0); // Create TopLevel-Widget
    //setAttribute(Qt::WA_NoSystemBackground, true);
    //setAttribute(Qt::WA_TranslucentBackground, true);
    //setAttribute(Qt::WA_PaintOnScreen); // as pointed by Caveman (thanks!)


    ui->lblBottom->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblBottomLeft->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblBottomRight->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    //ui->lblCenter->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblLeft->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblRight->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblTop->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblTopLeft->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    ui->lblTopRight->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");


}

Widget::~Widget()
{
    delete ui;
}
