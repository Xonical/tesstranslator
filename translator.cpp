#include "translator.h"
#include "ui_translator.h"
#include "historydelegate.h"
#include "imagecrop.h"
#include "trainer.h"

Translator::Translator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Translator)
{
    ui->setupUi(this);
    isCalledFromButton = true;


    bool isInit = this->initDB();
    if(isInit){
        this->createModel();




        //        connect(ui.bookTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        //                mapper, SLOT(setCurrentModelIndex(QModelIndex)));
        //        ui.bookTable->setCurrentIndex(model->index(0, 0));
    }

    QNetworkProxy proxy;
    //proxy.setType(QNetworkProxy::DefaultProxy);
    //proxy.setType(QNetworkProxy::Socks5Proxy);
    //proxy.setType(QNetworkProxy::HttpProxy);
    //proxy.setHostName("alfaproxy");
    //proxy.setPort(3128);


    //proxy.setType(QNetworkProxy::Socks5Proxy);
    proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("alfaproxy");
    proxy.setPort(3128);

    QNetworkProxy::setApplicationProxy(proxy);


//    createActions();


//    createTrayIcon();


//    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(messageClicked()));
//    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
//            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));


    QRect rect = ui->tableView->geometry();
    ui->tableView->setGeometry(rect.x(),rect.y(),777,rect.height());

    QRect geoThis = this->geometry();
    //point = this->mapToGlobal(QPoint( geoThis.x(),geoThis.y));
    QRect geoWebView = ui->webView->geometry();

    this->setGeometry(geoWebView.x()+555,geoWebView.y() +44,geoThis.x()-geoWebView.x(),
                      geoThis.height());
 /*                     */

    //ui->webView->setUrl(QUrl("https://translate.google.de/#en/de/"));
    //this->setTextToTranslate("eat");
     //this->hide();

//    Widget *w = new Widget(this);
//    w->show();
}

Translator::~Translator()
{
    delete ui;
}

void Translator::setTextToTranslate(QString source)
{
    this->isCalledFromButton = false;
    this->source = source;
    QString google = "https://translate.google.de/#en/de/";
    ui->webView->setUrl(QUrl(google + source));
}

void Translator::setTrayIcon(QSystemTrayIcon *trayIcon)
{
    this->trayIcon = trayIcon;
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(messageClicked()));
}

void Translator::setUrlFromButton(QString url)
{
    this->isCalledFromButton = true;
    if(ui->btnShowBrowser->text() == ">>"){
        ui->webView->setVisible(true);
        ui->btnShowBrowser->setText("<<");
    }
    ui->webView->setUrl(QUrl(url));
}

//void Translation::setVisible(bool visible)
//{
//    qDebug() << "fooo123";
//    minimizeAction->setEnabled(visible);
//    restoreAction->setEnabled(isMaximized() || !visible);
//    QDialog::setVisible(visible);
//}

void Translator::closeEvent(QCloseEvent *event)
{
   // if (trayIcon->isVisible()) {
        hide();
        event->ignore();
    //}
}

bool Translator::initDB()
{
    QString dbPath = "d:/MyQT_Project/tesstranslator.db";

    if(QFileInfo(dbPath).isFile()){

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbPath);

        if(! db.open()){
            QMessageBox::critical(this, tr("Information"),
                                  tr("Datenbank konnte nicht geladen werden"));
            return false;
        }
    }else{
        QMessageBox::critical(this, tr("Information"),
                              tr("Datenbank konnte nicht gefunden werden"));
        return false;
    }
    return true;
}

void Translator::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                          "Error initializing database: " + err.text());
}

void Translator::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(trainerAction);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);

    trayIcon->setVisible(true);
    QIcon icon = QIcon("D:/MyQT_Project/TessTranslator/images/heart.png");
    trayIcon->setIcon(icon);
    setWindowIcon(icon);

    trayIcon->setToolTip("TessTranslator");
}

void Translator::createActions()
{
    Trainer *trainer = new Trainer(this);


    trainerAction = new QAction(tr("&Trainer"), this);
    connect(trainerAction, SIGNAL(triggered()), trainer, SLOT(exec()));

    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void Translator::createModel()
{
    model = new QSqlRelationalTableModel(ui->tableView);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("eng_ger");

    model->setHeaderData(model->fieldIndex("eng"), Qt::Horizontal, tr("Englisch"));
    model->setHeaderData(model->fieldIndex("ger"), Qt::Horizontal, tr("Deutsch"));
    model->setHeaderData(model->fieldIndex("date"), Qt::Horizontal, tr("Zeitpunkt"));
    model->setHeaderData(model->fieldIndex("link"), Qt::Horizontal, tr("Link"));

    if (!model->select()) {
        QMessageBox::critical(this, tr("Error"),
                              model->lastError().text());
    }






    // Remember the indexes of the columns
    //authorIdx = model->fieldIndex("author");
    //genreIdx = model->fieldIndex("genre");

    // Set the relations to the other database tables
    //model->setRelation(authorIdx, QSqlRelation("authors", "id", "name"));
    //model->setRelation(genreIdx, QSqlRelation("genres", "id", "name"));

    // Set the localized header captions
    //model->setHeaderData(authorIdx, Qt::Horizontal, tr("Author Name"));
    //model->setHeaderData(genreIdx, Qt::Horizontal, tr("Genre"));
    //        model->setHeaderData(model->fieldIndex("title"), Qt::Horizontal, tr("Title"));
    //        model->setHeaderData(model->fieldIndex("year"), Qt::Horizontal, tr("Year"));
    //        model->setHeaderData(model->fieldIndex("rating"), Qt::Horizontal, tr("Rating"));


    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new HistoryDelegate(ui->tableView,this));

ui->tableView->setColumnHidden(model->fieldIndex("eng_ger_id"), true);

}



//void Translation::on_webView_loadFinished(bool arg1)
//{
//    if(arg1){

//        QWebElement e = ui->webView->page()
//                //->mainFrame()->findFirstElement("span class=\"gt-card-ttl-txt\" style=\"direction: ltr;\"");

//                // Ausgabe :eat
//                //->currentFrame()->findFirstElement("span.gt-card-ttl-txt");

//                ->currentFrame()->findFirstElement("span#result_box");

//                qDebug() << "e: " << e.toPlainText();




//                QSqlRecord record;
//                QSqlField f2("eng", QVariant::String);
//                QSqlField f3("ger", QVariant::String);
//                f2.setValue(QVariant(source));
//                f3.setValue(QVariant(e.toPlainText()));
//                record.append(f2);
//                record.append(f3);
//                model->insertRecord(-1,record);
//    }
//}




void Translator::on_btnDumm_clicked()
{
    qDebug() << "no gg";
        ui->webView->setVisible(false);
}

void Translator::on_webView_loadFinished(bool arg1)
{
    if(! isCalledFromButton){
        QWebElement e = ui->webView->page()
                ->currentFrame()->findFirstElement("span#result_box");

        this->showMessage(e.toPlainText(),this->source);
    }





}

void Translator::showMessage(QString target, QString source)
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(0);

    QString txt = source + " - " + target;
    qDebug() << "TXT_ " << txt;
    this->trayIcon->showMessage(txt,"",icon,15 *1000);


    QSqlRecord record;
    QSqlField f2("eng", QVariant::String);
    QSqlField f3("ger", QVariant::String);
    QSqlField f4("date", QVariant::String);
    QSqlField f5("link", QVariant::String);
    f2.setValue(QVariant(source));
    f3.setValue(QVariant(target));

    QDateTime *dateTime = new QDateTime();


    f4.setValue(QVariant(dateTime->currentDateTime().toString()));
    f5.setValue(QVariant("https://translate.google.de/#en/de/" + this->source));

    record.append(f2);
    record.append(f3);
    record.append(f4);
    record.append(f5);
    //model->insertRecord(-1,record);
    model->insertRecord(-1,record);
    model->submit();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);



 }

void Translator::messageClicked()
{
//    QMessageBox::information(0, tr("Systray"),
//                             tr("Sorry, I already gave what help I could.\n"
//                                "Maybe you should try asking a human?"));
    qDebug() << "Damn show ";
    this->show();
}


void Translator::on_btnInsert_clicked()
{
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record;
    QSqlField f2("eng", QVariant::String);
    QSqlField f3("ger", QVariant::String);
    QSqlField f4("date", QVariant::String);
    QSqlField f5("link", QVariant::String);
    f2.setValue(QVariant("awesome"));
    f3.setValue(QVariant("genial"));

    QDateTime *dateTime = new QDateTime();


    f4.setValue(QVariant(dateTime->currentDateTime().toString()));
    f5.setValue(QVariant("http://www.google.de"));

    record.append(f2);
    record.append(f3);
    record.append(f4);
    record.append(f5);
    //model->insertRecord(-1,record);
    model->insertRecord(-1,record);
    model->submitAll();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
}

void Translator::on_btnShowBrowser_clicked(bool checked)
{
    if(ui->btnShowBrowser->text() == ">>"){
        ui->webView->setVisible(true);
        ui->btnShowBrowser->setText("<<");
    }else{
        ui->webView->setVisible(false);
        ui->btnShowBrowser->setText(">>");
    }
}
