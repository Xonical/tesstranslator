#ifndef TRAINER_H
#define TRAINER_H

#include <QDialog>

namespace Ui {
class trainer;
}

class Trainer : public QDialog
{
    Q_OBJECT

public:
    explicit Trainer(QWidget *parent = 0);
    ~Trainer();

private:
    Ui::trainer *ui;
};

#endif // TRAINER_H
