/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btnThisMoveTo;
    QLineEdit *txtThisX;
    QLineEdit *txtThisY;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btnQLabelMoveTo;
    QLineEdit *txtQLabelX;
    QLabel *label_7;
    QLineEdit *txtQLabelY;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *lblThisMapFromGlobal;
    QLabel *lblThisMapToGlobal;
    QLabel *lblQLabelMapToGlobal;
    QLabel *lblQLabelMapFromGlobal;
    QLabel *lblMoveableQLabel;
    QPushButton *btnAktualisieren;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        btnThisMoveTo = new QPushButton(Widget);
        btnThisMoveTo->setObjectName(QStringLiteral("btnThisMoveTo"));
        btnThisMoveTo->setGeometry(QRect(120, 30, 131, 23));
        txtThisX = new QLineEdit(Widget);
        txtThisX->setObjectName(QStringLiteral("txtThisX"));
        txtThisX->setGeometry(QRect(260, 30, 51, 20));
        txtThisY = new QLineEdit(Widget);
        txtThisY->setObjectName(QStringLiteral("txtThisY"));
        txtThisY->setGeometry(QRect(330, 30, 51, 20));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 91, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 10, 46, 13));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 10, 46, 13));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 70, 101, 16));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 90, 111, 16));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 270, 141, 16));
        btnQLabelMoveTo = new QPushButton(Widget);
        btnQLabelMoveTo->setObjectName(QStringLiteral("btnQLabelMoveTo"));
        btnQLabelMoveTo->setGeometry(QRect(120, 210, 131, 23));
        txtQLabelX = new QLineEdit(Widget);
        txtQLabelX->setObjectName(QStringLiteral("txtQLabelX"));
        txtQLabelX->setGeometry(QRect(260, 210, 51, 20));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 190, 46, 13));
        txtQLabelY = new QLineEdit(Widget);
        txtQLabelY->setObjectName(QStringLiteral("txtQLabelY"));
        txtQLabelY->setGeometry(QRect(330, 210, 51, 20));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(330, 190, 46, 13));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(120, 190, 91, 16));
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(120, 250, 151, 16));
        lblThisMapFromGlobal = new QLabel(Widget);
        lblThisMapFromGlobal->setObjectName(QStringLiteral("lblThisMapFromGlobal"));
        lblThisMapFromGlobal->setGeometry(QRect(260, 90, 111, 16));
        lblThisMapToGlobal = new QLabel(Widget);
        lblThisMapToGlobal->setObjectName(QStringLiteral("lblThisMapToGlobal"));
        lblThisMapToGlobal->setGeometry(QRect(260, 70, 101, 16));
        lblQLabelMapToGlobal = new QLabel(Widget);
        lblQLabelMapToGlobal->setObjectName(QStringLiteral("lblQLabelMapToGlobal"));
        lblQLabelMapToGlobal->setGeometry(QRect(270, 250, 101, 16));
        lblQLabelMapFromGlobal = new QLabel(Widget);
        lblQLabelMapFromGlobal->setObjectName(QStringLiteral("lblQLabelMapFromGlobal"));
        lblQLabelMapFromGlobal->setGeometry(QRect(270, 270, 101, 16));
        lblMoveableQLabel = new QLabel(Widget);
        lblMoveableQLabel->setObjectName(QStringLiteral("lblMoveableQLabel"));
        lblMoveableQLabel->setGeometry(QRect(120, 130, 121, 41));
        lblMoveableQLabel->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 127);"));
        btnAktualisieren = new QPushButton(Widget);
        btnAktualisieren->setObjectName(QStringLiteral("btnAktualisieren"));
        btnAktualisieren->setGeometry(QRect(20, 250, 75, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        btnThisMoveTo->setText(QApplication::translate("Widget", "this->move To:", 0));
        label->setText(QApplication::translate("Widget", "this->Widget:", 0));
        label_2->setText(QApplication::translate("Widget", "x:", 0));
        label_3->setText(QApplication::translate("Widget", "y:", 0));
        label_4->setText(QApplication::translate("Widget", "this->mapToGlobal", 0));
        label_5->setText(QApplication::translate("Widget", "this->mapFromGlobal", 0));
        label_6->setText(QApplication::translate("Widget", "this->QLabelmapFromGlobal", 0));
        btnQLabelMoveTo->setText(QApplication::translate("Widget", "this->QLabel->move To:", 0));
        label_7->setText(QApplication::translate("Widget", "x:", 0));
        label_8->setText(QApplication::translate("Widget", "y:", 0));
        label_9->setText(QApplication::translate("Widget", "this->QLabel:", 0));
        label_10->setText(QApplication::translate("Widget", "this->QLabelmapToGlobal", 0));
        lblThisMapFromGlobal->setText(QString());
        lblThisMapToGlobal->setText(QString());
        lblQLabelMapToGlobal->setText(QString());
        lblQLabelMapFromGlobal->setText(QString());
        lblMoveableQLabel->setText(QString());
        btnAktualisieren->setText(QApplication::translate("Widget", "Aktualisieren:", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
