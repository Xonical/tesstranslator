#include "translation.h"
#include "ui_translation.h"
#include "bookdelegate.h"

Translation::Translation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Translation)
{
    ui->setupUi(this);
    bool isInit = this->initDB();
    if(isInit){
        this->createModel();
        ui->tableView->setItemDelegate(new BookDelegate(ui->tableView));
        ui->tableView->setColumnHidden(model->fieldIndex("eng_ger_id"), true);
        ui->tableView->setModel(model);
        //        connect(ui.bookTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
        //                mapper, SLOT(setCurrentModelIndex(QModelIndex)));
        //        ui.bookTable->setCurrentIndex(model->index(0, 0));
    }

    QNetworkProxy proxy;
    //proxy.setType(QNetworkProxy::DefaultProxy);
    proxy.setType(QNetworkProxy::Socks5Proxy);
    proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("alfaproxy");
    proxy.setPort(3128);
    QNetworkProxy::setApplicationProxy(proxy);


    createActions();
    createTrayIcon();
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(messageClicked()));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));


    QRect rect = ui->tableView->geometry();
    ui->tableView->setGeometry(rect.x(),rect.y(),777,rect.height());

    QRect geoThis = this->geometry();
    //point = this->mapToGlobal(QPoint( geoThis.x(),geoThis.y));
    QRect geoWebView = ui->webView->geometry();

    this->setGeometry(geoWebView.x()+555,geoWebView.y() +44,geoThis.x()-geoWebView.x(),
                      geoThis.height());
}

Translation::~Translation()
{
    delete ui;
}

void Translation::setTextToTranslate(QString source)
{
    this->source = source;
    QString google = "https://translate.google.de/#en/de/";
    ui->webView->setUrl(QUrl(google + source));
}

void Translation::setVisible(bool visible)
{
    minimizeAction->setEnabled(visible);
    restoreAction->setEnabled(isMaximized() || !visible);
    QDialog::setVisible(visible);
}

void Translation::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        QMessageBox::information(this, tr("Systray"),
                                 tr("The program will keep running in the "
                                    "system tray. To terminate the program, "
                                    "choose <b>Quit</b> in the context menu "
                                    "of the system tray entry."));
        hide();
        event->ignore();
    }
}

bool Translation::initDB()
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

void Translation::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                          "Error initializing database: " + err.text());
}

void Translation::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
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

void Translation::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void Translation::createModel()
{
    model = new QSqlRelationalTableModel(ui->tableView);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("eng_ger");
    model->setHeaderData(model->fieldIndex("eng"), Qt::Horizontal, tr("Englisch"));
    model->setHeaderData(model->fieldIndex("ger"), Qt::Horizontal, tr("Deutsch"));



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



    if (!model->select()) {
        QMessageBox::critical(this, tr("Error"),
                              model->lastError().text());
    }
}


/*
void Translation::on_webView_loadFinished(bool arg1)
{
    if(arg1){

        QWebElement e = ui->webView->page()
                //->mainFrame()->findFirstElement("span class=\"gt-card-ttl-txt\" style=\"direction: ltr;\"");

                // Ausgabe :eat
                //->currentFrame()->findFirstElement("span.gt-card-ttl-txt");

                ->currentFrame()->findFirstElement("span#result_box");

                qDebug() << "e: " << e.toPlainText();




                QSqlRecord record;
                QSqlField f2("eng", QVariant::String);
                QSqlField f3("ger", QVariant::String);
                f2.setValue(QVariant(source));
                f3.setValue(QVariant(e.toPlainText()));
                record.append(f2);
                record.append(f3);
                model->insertRecord(-1,record);
    }
}*/




void Translation::on_btnShowBrowser_clicked()
{
    qDebug() << "gg";
    ui->webView->setVisible(true);

}

void Translation::on_btnDumm_clicked()
{
    qDebug() << "no gg";
        ui->webView->setVisible(false);
}

void Translation::on_webView_loadFinished(bool arg1)
{
    /*
    QWebElement e = ui->webView->page()
            //->mainFrame()->findFirstElement("span class=\"gt-card-ttl-txt\" style=\"direction: ltr;\"");

            // Ausgabe :eat
            //->currentFrame()->findFirstElement("span.gt-card-ttl-txt");

            ->currentFrame()->findFirstElement("span#result_box");

            qDebug() << "e: " << e.toPlainText();




            QSqlRecord record;
            QSqlField f2("eng", QVariant::String);
            QSqlField f3("ger", QVariant::String);
            f2.setValue(QVariant(source));
            f3.setValue(QVariant(e.toPlainText()));
            record.append(f2);
            record.append(f3);
            model->insertRecord(-1,record);
            */
}

void Translation::showMessage()
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(0);
    trayIcon->showMessage("Title", "Nachricht", icon,
                          10 * 1000);
}

void Translation::messageClicked()
{
    QMessageBox::information(0, tr("Systray"),
                             tr("Sorry, I already gave what help I could.\n"
                                "Maybe you should try asking a human?"));
}


void Translation::on_btnBallon_clicked()
{
    showMessage();
}
