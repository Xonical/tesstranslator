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

    bool isInit = this->initDB();
    if(isInit){
        this->createModel();
    }

    QNetworkProxy proxy;
    //proxy.setType(QNetworkProxy::DefaultProxy);
    //proxy.setType(QNetworkProxy::Socks5Proxy);
    //proxy.setType(QNetworkProxy::HttpProxy);
    //proxy.setHostName("-------");
    //proxy.setPort(3128);

    QNetworkProxy::setApplicationProxy(proxy);

    QRect rect = ui->tableView->geometry();
    ui->tableView->setGeometry(rect.x(),rect.y(),777,rect.height());

    QRect geoThis = this->geometry();
    //point = this->mapToGlobal(QPoint( geoThis.x(),geoThis.y));
    QRect geoWebView = ui->webView->geometry();

    this->setGeometry(geoWebView.x()+555,geoWebView.y() +44,geoThis.x()-geoWebView.x(),
                      geoThis.height());
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
    ui->webView->setUrl(QUrl(url));
}

void Translator::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}

bool Translator::initDB()
{
    // FYI: Use valid path
    QString dbPath = "tesstranslator.db";

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
    QIcon icon = QIcon("qrc:/images/images/tesstranslator.png");
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

    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new HistoryDelegate(ui->tableView,this));

    ui->tableView->setColumnHidden(model->fieldIndex("eng_ger_id"), true);
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
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    QString txt = source + " - " + target;
    qDebug() << "TXT_ " << txt;


    QSqlRecord record;
    QSqlField f2("eng", QVariant::String);
    QSqlField f3("ger", QVariant::String);
    QSqlField f4("date", QVariant::String);
    QSqlField f5("link", QVariant::String);
    f2.setValue(QVariant(source));
    f3.setValue(QVariant(target));

    QDateTime *dateTime = new QDateTime();

    f4.setValue(QVariant(dateTime->currentDateTime().time().toString()));
    f5.setValue(QVariant("https://translate.google.de/#en/de/" + this->source));

    record.append(f2);
    record.append(f3);
    record.append(f4);
    record.append(f5);
    model->insertRecord(-1,record);
    qDebug() << "Erfolgreich? " << model->submitAll();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(0);
    this->trayIcon->showMessage(txt,"",icon,15 *1000);
}

void Translator::messageClicked()
{
    this->show();
}
