#include "actionform.h"
#include "ui_actionform.h"

ActionForm::ActionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionForm)
{
    ui->setupUi(this);
}

ActionForm::~ActionForm()
{
    delete ui;
}
