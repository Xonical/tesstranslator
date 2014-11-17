#include "databasebuilder.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>


DatabaseBuilder::DatabaseBuilder(QObject *parent) : QObject(parent)
{
    QString currentPath = QDir::currentPath();
    QString databaseName = "tesstranslator.db";
    databasePathName = currentPath + "/" + databaseName;

    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName(databasePathName);

    QDir dir;
    if(! dir.exists(databasePathName)){
        createDatabase();
    }
}

QString DatabaseBuilder::getDatabasePathName()
{
    return this->databasePathName;
}

DatabaseBuilder::deleteDatabaseFile()
{
    db.close();
   bool isSuccessful = QFile::remove(this->databasePathName);

   if(! isSuccessful ){
       QMessageBox msgBox;
       msgBox.setText("Datenbank konnte nicht neu erstellt werden.");
       msgBox.exec();
   }
}

DatabaseBuilder::~DatabaseBuilder()
{

}

DatabaseBuilder::createDatabase()
{
    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }

    QStringList stringList;
    stringList << "CREATE TABLE eng_ger (eng_ger_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
               << "eng TEXT DEFAULT '', "
                  "ger TEXT DEFAULT '')";

    QSqlQuery query;
    query.prepare(stringList.join(""));

    query.exec();
}

