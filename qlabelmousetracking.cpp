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
#include "translator.h"
#include "imagecrop.h"

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
      //  this->setStyleSheet("background-color: rgba(139, 169, 119, 0.7)");
this->setStyleSheet("background-color: rgba(022, 46, 111, 0.5)");

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


    QRect geo = mainWidget->geometry();
    QPixmap pixCopy = pix.copy(geo.x(),geo.y(),geo.width(),geo.height());

    QString format = "png";
    QString pathPix = "d:/MyQT_Project";
    QString fileName;
    fileName = (QString::number(QDateTime::currentDateTime().toTime_t()));

    pixCopy.save(pathPix+ "/" + fileName+".png", format.toLatin1().constData());




    // Example %Path% + tesseract.exe  croppedImage.png test2 -eng
    // I used the escaped backslash, because slash didn't work

//    QString  foo = "\"d:\\MyQT_Project\\"; // The string contains spaces, that the reason für double qoutes
//    foo.append("tesseract.exe");
//    QString path = " d:\\MyQT_Project\\";

    QString  foo = "\"d:\\MyQT_Project\\"; // The string contains spaces, that the reason für double qoutes
    foo.append("tesseract.exe");
    QString path = "d:\\MyQT_Project\\";


    foo.append(path);
    foo.append(fileName);
    foo.append(".png");
    foo.append(path);
    foo.append(fileName); // The output file gets automatic a txt-Extension
    foo.append(" -eng\"");

    //foo = """d:\\MyQT_Project\\tesseract.exe  d:\\MyQT_Project\\1402617176.png d:\\MyQT_Project\\1402617176 -eng""";
    qDebug()<< foo;
    //process->start("cmd /k" + foo);
    //process->waitForFinished();

    QStringList args;
    args.append(path + fileName + ".png");
    args.append(path + fileName);
    args.append("-eng");

//    args.append(path + fileName + ".png");
//    args.append(path + fileName);
//    args.append(" -eng\"");
    qDebug()<< "QStringList" << args;
QProcess *process = new QProcess(this);




//    qDebug()<< "!!: " << process->isReadable();
//    qDebug()<< "??: " << process->isWritable();
    process->start("d:\\MyQT_Project\\tesseract.exe",args,QIODevice::ReadOnly);

    process->waitForFinished();

    QString txtFile = pathPix+ "/" + fileName+".txt";
    qDebug() << "Read txt: " << txtFile;


    //QThread *thread = new QThread(this);

//    while(true){
//        qDebug() << "READ";
//        if(file.exists(txtFile))break;
//        thread->sleep(1000);
//    }
    //thread->sleep(1000);
   // process->close();


QFile file(txtFile);

    QString doc;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QString line;
        QTextStream stream(&file);

        do{
            line = stream.readLine();
            doc += line;
            qDebug() << "Line " <<line;
        }while(! line.isNull());


        //The reason for no loop is, that the translation is in one line

    }
    file.close();
    qDebug() << "Was steht: " << doc;
    mainWidget->show();




//     QPointer<Translator> oo = this->tt;
//     if (oo.isNull()){
//         this->tt = new Translator();
//         qDebug() << "ififififif";
//     }else{
//         qDebug() << "elseelseelse";
//     }

//     tt->show();

     //tt->setTextToTranslate(doc);

    // Downcast mainWidget to get the reference of translator
    ImageCrop *ic  = qobject_cast<ImageCrop *>(mainWidget);
    ic->translator->setTextToTranslate(doc);



    //https://translate.google.de/#en/de/eaten
    //tWid->setTextToTranslate("https://translate.google.de/#en/de/" +doc);

//http://dict.leo.org/ende/index_de.html#/search=cinema&searchLoc=0&resultOrder=basic&multiwordShowSingle=on
}

void QLabelMouseTracking::expandToBottom(QMouseEvent *ev)
{
    QWidget *mainWidget = this->parentWidget();
    QRect geo = mainWidget->geometry();
    mainWidget->setGeometry(geo.x(),geo.y(),geo.width(),geo.height() + ev->y());
}
