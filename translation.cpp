#include "translation.h"
#include "ui_translation.h"

Translation::Translation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Translation)
{
    ui->setupUi(this);
}

Translation::~Translation()
{
    delete ui;
}
