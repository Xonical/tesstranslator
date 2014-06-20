#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QIcon>
#include <translator.h>

namespace Ui {
class Widget;
}

class ImageCrop : public QWidget
{
    Q_OBJECT

public:
    explicit ImageCrop(QWidget *parent = 0);
    Translator *dlgTranslate;
    void setTranslator(Translator *translator);
    Translator *translator;
    ~ImageCrop();

private:
    Ui::Widget *ui;
    void initActionForm();


public slots:
    void doLater();
};

#endif // WIDGET_H
