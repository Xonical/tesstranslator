#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setVisible(true);
    dbc  = new DatabaseBuilder();
   ui->lineEdit->setText(dbc->getDatabasePathName());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonNewDatabase_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "TessTranslator", "Datenbank wirklich neu erstellen (Daten werden gelöscht)?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      dbc->deleteDatabaseFile();
      dbc->createDatabase();
      ui->lineEdit->setText(dbc->getDatabasePathName());
      QMessageBox::information(this,"TessTranslator","Datenbank wurde neu erstellt.");
    }
}
