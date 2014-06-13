#include "qlabelmousetracking.h"
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include <QString>
#include <QWidget>
#include <QPixmap>
#include <QScreen>
#include <QDir>
#include <QProcess>
#include <QTemporaryFile>
#include <QDateTime>
#include <QThread>
#include <QFile>

QLabelMouseTracking::QLabelMouseTracking(QWidget *parent) :
    QLabel(parent)
{
    this->setMouseTracking(true);
}

void QLabelMouseTracking::mouseMoveEvent(QMouseEvent *ev)
{
    if (this->objectName() == "lblCenter"){
        setCursor( Qt::OpenHandCursor);

        if (ev->buttons() == Qt::LeftButton ){
            this->moveWidget(ev,this);
        }
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

        if (ev->buttons() == Qt::LeftButton ){
            this->expandToBottom(ev);
        }
    }else if(this->objectName() == "lblTopLeft"){
        setCursor( Qt::SizeFDiagCursor );
    }else if(this->objectName() == "lblTopRight"){
        setCursor( Qt::SizeBDiagCursor );
    }else if(this->objectName() == "lblBottomLeft"){
        setCursor( Qt::SizeBDiagCursor);
    }else if(this->objectName() == "lblBottomRight"){
        setCursor( Qt::SizeFDiagCursor );
    }

    // To add a hover effect to each border-label
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

    //Needed to handle the position by moving MainWidget
    mousePressedGlobalX = ev->pos().x();
    mousePressedGlobalY = ev->pos().y();
    emit Mouse_Pressed();
}

void QLabelMouseTracking::leaveEvent(QEvent *ev)
{
    if (this->objectName() != "lblCenter"){
        this->setStyleSheet("background-color: rgba(255, 235, 205, 0.7)");
    }

    emit Mouse_Left();
}

void QLabelMouseTracking::mouseDoubleClickEvent(QMouseEvent *ev)
{
       if (this->objectName() == "lblCenter"){
           this->createCropedScreenshot(ev);
       }
}

void QLabelMouseTracking::setCentralQLabel(QLabel *label)
{
    this->centralQLabel= label;
}

void QLabelMouseTracking::expandToLeft(QMouseEvent *ev, QLabel *label)
{
    QWidget *mainWidget = this->parentWidget();

    int newWeight = 0;
    //Wird negiert, da nach Bewegung außerhalb negative Werte auslößt
    int toGrowToRight = (ev->x()*-1);
    int newX = ev->globalX();
    int newSize = mainWidget->width() + toGrowToRight;

    int y = mainWidget->geometry().y();
    int height = mainWidget->geometry().height();

    if (this->rightBorderX == newSize){
         mainWidget->setGeometry(newX,y,newSize,height);
    }

    if(newSize < 20){
         newSize = 20; // Minimum Width of the widget
    }else{
        mainWidget->setGeometry(ev->globalX(),y,newSize,height);
    }
}

void QLabelMouseTracking::moveWidget(QMouseEvent *ev, QLabel *label)
{
    QWidget *mainWidget = label->parentWidget();
    QPoint globalPoint = label->mapToGlobal( ev->globalPos() );


    QRect geo = mainWidget->geometry();
    mainWidget->move(geo.x() + ev->x() - this->mousePressedGlobalX,
                     geo.y() + ev->y() - this->mousePressedGlobalY);
}

void QLabelMouseTracking::createCropedScreenshot(QMouseEvent *ev)
{
    QWidget *mainWidget = this->parentWidget();
    mainWidget->hide();

    QPixmap pix =  QPixmap(); // clear image for low memory situations                            // on embedded devices.
    pix = QPixmap::grabWindow(QApplication::desktop()->winId());

    mainWidget->show();
    QRect geo = mainWidget->geometry();
    QPixmap pixCopy = pix.copy(geo.x(),geo.y(),geo.width(),geo.height());

    QString format = "png";
    //QString initialPath = QDir::currentPath() + tr("/untitled.") + format;
    //QString fileName = "d:/croppedImage." + format;

//    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
//                               initialPath,
//                               tr("%1 Files (*.%2);;All Files (*)")
//                               .arg(format.toUpper())
//                               .arg(format));

      //QDir::tempPath();
    QString path = "d:/MyQT_Project";
    QString fileName;
    fileName = (QString::number(QDateTime::currentDateTime().toTime_t()));

    //QThread *t = new QThread(mainWidget);
    //pixCopy.save(path+ "/" + fileName+".png", format.toLatin1().constData());


    //t->msleep(4000);


    QProcess *process = new QProcess(this);
     //tesseract  croppedImage.png test2.txt -eng

    fileName = "1402617176";
    QString foo = "d:\\MyQT_Project\\tesseract.exe " + fileName +".png "
            +fileName+" -eng";

    QString bar = "d:\\MyQT_Project\\" + fileName +".png";


    qDebug()<< QFile::exists("d:\\MyQT_Project\\tesseract.exe");
    qDebug()<< "1: " << QFile::exists(bar);

    while(false){
        if(QFile::exists(bar)){
          qDebug()<< "2: " << QFile::exists(bar);
                break;
        }
    }
    qDebug()<< "3: " << QFile::exists(bar);

    //t->msleep(40000);

    //Works
    //process->start("d:\\MyQT_Project\\msiexec.exe");

    foo = """d:\\MyQT_Project\\tesseract.exe  d:\\MyQT_Project\\1402617176.png d:\\MyQT_Project\\1402617176 -eng""";
    qDebug()<< foo;
    process->start(foo);

}

void QLabelMouseTracking::expandToBottom(QMouseEvent *ev)
{
    QWidget *mainWidget = this->parentWidget();
    QRect geo = mainWidget->geometry();
    mainWidget->setGeometry(geo.x(),geo.y(),geo.width(),geo.height() + ev->y());
}
