#include "translation.h"
#include "ui_translation.h"

Translation::Translation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Translation)
{
    ui->setupUi(this);
    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::DefaultProxy);
    //proxy.setType(QNetworkProxy::Socks5Proxy);
    //proxy.setType(QNetworkProxy::HttpProxy);
    //proxy.setHostName("alfaproxy");
    //proxy.setPort(3128);
    // proxy.setUser("username");
    // proxy.setPassword("password");
    QNetworkProxy::setApplicationProxy(proxy);


    //QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("d:/MyQT_Project/tesstranslator.db");





}

Translation::~Translation()
{
    delete ui;
}

void Translation::setUrl(QString url)
{
    ui->webView->setUrl(QUrl(url));
}

void Translation::on_pushButton_7_clicked()
{
    initDB();
}

void Translation::initDB()
{
    QFileInfo checkFile("d:/MyQT_Project/tesstranslator.db");

    if(checkFile.isFile()){

        if(! db.open()){
            qDebug() << "Database could not loaded";
            return;
        }

        int num_rows,r,c;
        QSqlQuery q;
        //QString str = "SELECT * as num_rows FROM eng_ger";
        if(!q.exec ("SELECT count(eng_ger_id) as num_rows FROM eng_ger"))
        {
            qDebug() << q.lastError().text();
        }
        q.first();
        num_rows = q.value(0).toInt();
        qDebug() << num_rows;

//        while(qry.next()){
//           qDebug() << qry.value(1).toString();
//           qDebug() << qry.value(2).toString();
//           qDebug() << qry.value(3).toBool();
//        }
    }




}

void Translation::on_pushButton_6_clicked(bool checked)
{

    if(checked){
        ui->tableView->show();
        //QSize s;
        //s.setHeight(0);
        //s.setWidth(0);
        //ui->horizontalLayout->maximumSize(new QSize(0,0));
    }
    else{
        ui->tableView->hide();

    }
}
