#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QDialog>
#include <QUrl>
#include <QNetworkProxy>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSize>

namespace Ui {
class Translation;
}

class Translation : public QDialog
{
    Q_OBJECT

public:
    explicit Translation(QWidget *parent = 0);
    ~Translation();
    void setUrl(QString url);

private slots:
    void on_pushButton_7_clicked();


    void on_pushButton_6_clicked(bool checked);

private:
    Ui::Translation *ui;
    QSqlDatabase db;
    void initDB();
};

#endif // TRANSLATION_H
