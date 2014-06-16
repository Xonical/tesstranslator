#ifndef ACTIONFORM_H
#define ACTIONFORM_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QWidgetList>

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

public slots:
    void doLater();
};

#endif // ACTIONFORM_H
