#include "imagecrop.h"
#include "ui_imagecrop.h"
#include <QTimer>



ImageCrop::ImageCrop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QIcon icon = QIcon("images/tesstranslator.png");
    this->setWindowIcon(icon);

    ui->lblLeft->setCentralQLabel(ui->lblCenter);
    ui->horizontalLayout->setContentsMargins(0,0,0,0);

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

    int x = -1600; int y =0; int width = 1280; int height = 1024;
    this->setGeometry(x,y,width,height);

    QTimer::singleShot(1000, this, SLOT(doLater()));

}

void ImageCrop::setTranslator(Translator *translator)
{
    this->translator = translator;
}

ImageCrop::~ImageCrop()
{
    delete ui;
}

void ImageCrop::doLater()
{
    int x = 0; int y =0; int width = 1280; int height = 1024;
    bool toZoom = true;
    while(toZoom){
        if(x < 512){
            x++;
        }
        if(y < 20){
            y++;
        }

        if(width > 629){
            width--;
        }
        if(height > 327){
            height--;
        }
        this->setGeometry(x,y,width,height);
        if(x==512 && y == 20 &&
                width == 629 && height == 327){
            toZoom =false;
        }
    }
}

