#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QDialog>

namespace Ui {
class Translation;
}

class Translation : public QDialog
{
    Q_OBJECT

public:
    explicit Translation(QWidget *parent = 0);
    ~Translation();

private:
    Ui::Translation *ui;
};

#endif // TRANSLATION_H
