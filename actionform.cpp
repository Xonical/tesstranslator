#include "actionform.h"
#include "ui_actionform.h"

ActionForm::ActionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionForm)
{
    ui->setupUi(this);

    QWidgetList list = QApplication::topLevelWidgets();

    foreach (QWidget *wid, list) {

         if(wid->objectName()=="Widget"){
             qDebug() << "wid " << wid->objectName();
             //wid->setParent(this);
         }
    }

    QWidget *w = (  QApplication::topLevelWidgets().at(0) );
    qDebug() << w->objectName() << QApplication::topLevelWidgets().size();


    //w->setParent(0);


    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    //setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_NoSystemBackground, true);

    //setAttribute(Qt::WA_PaintOnScreen); // as pointed by Caveman (thanks!)







//background-color: rgba(022, 46, 111, 0.5)
    //this->hide();
    QTimer::singleShot(1000, this, SLOT(doLater()));


}

ActionForm::~ActionForm()
{
    delete ui;
}

void ActionForm::doLater()
{

}
