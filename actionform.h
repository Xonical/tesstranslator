#ifndef ACTIONFORM_H
#define ACTIONFORM_H

#include <QWidget>

namespace Ui {
class ActionForm;
}

class ActionForm : public QWidget
{
    Q_OBJECT

public:
    explicit ActionForm(QWidget *parent = 0);
    ~ActionForm();

private:
    Ui::ActionForm *ui;
};

#endif // ACTIONFORM_H
