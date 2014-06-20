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
#include <QSystemTrayIcon>
#include <QMenu>
#include <QDialog>
#include <QCloseEvent>
#include <QDate>
#include <QDateTime>

namespace Ui {
class Translation;
}

class Translator : public QDialog
{
    Q_OBJECT

public:
    explicit Translator(QWidget *parent = 0);
    ~Translator();
    void setTextToTranslate(QString source);
    void setTrayIcon(QSystemTrayIcon *trayIcon);
//    void setVisible(bool visible);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_btnShowBrowser_clicked();
    void on_btnDumm_clicked();
    void on_webView_loadFinished(bool arg1);
    void showMessage(QString target, QString source);
    void messageClicked();

    void on_btnBallon_clicked();

    void on_btnInsert_clicked();

private:
    Ui::Translation *ui;
    QSqlDatabase db;
    bool initDB();
    QSqlRelationalTableModel *model;
    void showError(const QSqlError &err);
    QString source;
    QHeaderView *m_horiz_header;
    void createTrayIcon();
    QSystemTrayIcon *trayIcon;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QAction *trainerAction;
    QMenu *trayIconMenu;
        void createActions();
        void createModel();

};

#endif // TRANSLATION_H
