#include "trainer.h"
#include "ui_trainer.h"

Trainer::Trainer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::trainer)
{
    ui->setupUi(this);
}

Trainer::~Trainer()
{
    delete ui;
}
