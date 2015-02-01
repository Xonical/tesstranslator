#ifndef DATABASECREATOR_H
#define DATABASECREATOR_H

#include <QObject>
#include <QtSql>
#include <QDir>
#include <QDebug>
#include <QStringList>

class DatabaseBuilder : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseBuilder(QObject *parent = 0);
    QString getDatabasePathName();
    deleteDatabaseFile();
    createDatabase();
    ~DatabaseBuilder();
private:
        QSqlDatabase db;
        QString databasePathName;



signals:

public slots:
};

#endif // DATABASECREATOR_H
