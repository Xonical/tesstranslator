#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QDialog>
#include <QUrl>
#include <QNetworkProxy>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSize>
#include <QMessageBox>
#include <QWebElement>
#include <QWebFrame>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QSortFilterProxyModel>

namespace Ui {
class Translation;
}

class Translation : public QDialog
{
    Q_OBJECT

public:
    explicit Translation(QWidget *parent = 0);
    ~Translation();
    void setTextToTranslate(QString source);

private slots:
    void on_pushButton_7_clicked();

    void on_sectionClicked(int index);

    void on_pushButton_6_clicked(bool checked);

    void on_webView_loadFinished(bool arg1);

    void on_pushButton_4_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::Translation *ui;
    QSqlDatabase db;
    void initDB();
    QSqlRelationalTableModel *model;
    void showError(const QSqlError &err);
    QString source;
    QHeaderView *m_horiz_header;
};

#endif // TRANSLATION_H
