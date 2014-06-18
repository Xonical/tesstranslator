#include "translation.h"
#include "ui_translation.h"
#include "bookdelegate.h"

Translation::Translation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Translation)
{
    ui->setupUi(this);
    QNetworkProxy proxy;
    //proxy.setType(QNetworkProxy::DefaultProxy);
    proxy.setType(QNetworkProxy::Socks5Proxy);
    proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("alfaproxy");
    proxy.setPort(3128);
    // proxy.setUser("username");
    // proxy.setPassword("password");
    QNetworkProxy::setApplicationProxy(proxy);

    QRect rect = ui->tableView->geometry();
    ui->tableView->setGeometry(rect.x(),rect.y(),777,rect.height());

    //QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("d:/MyQT_Project/tesstranslator.db");



        // Create the data model
        model = new QSqlRelationalTableModel(ui->tableView);
        //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->setTable("eng_ger");




        //model->setHeaderData(model->fieldIndex("eng"), Qt::Horizontal, tr("Englisch"));


        // Populate the model
        if (!model->select()) {
            showError(model->lastError());
            return;
        }


        m_horiz_header= ui->tableView->horizontalHeader();
        connect(m_horiz_header, SIGNAL(sectionClicked(int)), this, SLOT(on_sectionClicked(int)));



       // connect(ui->webView,SIGNAL())

        ui->tableView->setModel(model);
        //ui->tableView->setItemDelegate(new BookDelegate(ui->tableView));

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

//        // Populate the model
//        if (!model->select()) {
//            showError(model->lastError());
//            return;
//        }

        // Set the model and hide the ID column
//        ui.bookTable->setModel(model);
//        ui.bookTable->setItemDelegate(new BookDelegate(ui.bookTable));
//        ui.bookTable->setColumnHidden(model->fieldIndex("id"), true);
//        ui.bookTable->setSelectionMode(QAbstractItemView::SingleSelection);

//        // Initialize the Author combo box
//        ui.authorEdit->setModel(model->relationModel(authorIdx));
//        ui.authorEdit->setModelColumn(model->relationModel(authorIdx)->fieldIndex("name"));

//        ui.genreEdit->setModel(model->relationModel(genreIdx));
//        ui.genreEdit->setModelColumn(model->relationModel(genreIdx)->fieldIndex("name"));

//        QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
//        mapper->setModel(model);
//        mapper->setItemDelegate(new BookDelegate(this));
//        mapper->addMapping(ui.titleEdit, model->fieldIndex("title"));
//        mapper->addMapping(ui.yearEdit, model->fieldIndex("year"));
//        mapper->addMapping(ui.authorEdit, authorIdx);
//        mapper->addMapping(ui.genreEdit, genreIdx);
//        mapper->addMapping(ui.ratingEdit, model->fieldIndex("rating"));

//        connect(ui.bookTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
//                mapper, SLOT(setCurrentModelIndex(QModelIndex)));

//        ui.bookTable->setCurrentIndex(model->index(0, 0));



}

Translation::~Translation()
{
    delete ui;
}

void Translation::setTextToTranslate(QString source)
{
    this->source = source;
    QString google = "https://translate.google.de/#en/de/";
    //QString toTranslate = "Wow, you \"are\" so hungry;;;";
    ui->webView->setUrl(QUrl(google + source));




}

void Translation::on_pushButton_7_clicked()
{

}

void Translation::on_sectionClicked(int index)
{

    m_horiz_header->setSortIndicator(index, Qt::AscendingOrder);
    ui->tableView->sortByColumn(index);



    //QSortFilterProxyModel *proxyModel;
    //proxyModel->setSourceModel( model );
    //ui->tableView->setModel(proxyModel );
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
        //ui->tableView->show();
        //QSize s;
        //s.setHeight(0);
        //s.setWidth(0);
        //ui->horizontalLayout->maximumSize(new QSize(0,0));
    }
    else{
        //ui->tableView->hide();

    }
}

void Translation::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

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
}

void Translation::on_pushButton_4_clicked()
{
    qDebug() <<"HTML : " <<  ui->webView->page()->selectedHtml();
     qDebug() <<"TEXT : " <<  ui->webView->page()->selectedText();



}

void Translation::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug() << "dd: " << index;
}
