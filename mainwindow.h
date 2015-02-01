#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <databasebuilder.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonNewDatabase_clicked();

private:
    Ui::MainWindow *ui;
    DatabaseBuilder *dbc;
};

#endif // MAINWINDOW_H
