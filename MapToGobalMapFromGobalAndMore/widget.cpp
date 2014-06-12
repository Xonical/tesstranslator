#include "widget.h"
#include "ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0); // Create TopLevel-Widget
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_PaintOnScreen); // as pointed by Caveman (thanks!)
    */






}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnThisMoveTo_clicked()
{
    //QString mystring(1234);
    //int myint = mystring.toInt();

    this->move(ui->txtThisX->text().toInt(),ui->txtThisY->text().toInt());
}

void Widget::on_btnQLabelMoveTo_clicked()
{
    ui->lblMoveableQLabel->move(ui->txtQLabelX->text().toInt(),ui->txtQLabelY->text().toInt());
}

void Widget::on_pushButton_clicked()
{

}

void Widget::on_btnAktualisieren_clicked()
{

}
