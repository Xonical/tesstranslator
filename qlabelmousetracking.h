#ifndef QLABELMOUSETRACKING_H
#define QLABELMOUSETRACKING_H

#include <QLabel>
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QPoint>
#include <QRect>

class QLabelMouseTracking : public QLabel
{
    Q_OBJECT
public:
    explicit QLabelMouseTracking(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *ev);
    void setCentralQLabel(QLabel *label);
    void expandToLeft(QMouseEvent *ev, QLabel *label);
    void moveWidget(QMouseEvent *ev,QLabel *label);


    int x,y;

private:
    QLabel *centralQLabel;

    //used to calculate the resize at mouse move event
    QPoint buttonPressedGlobalPos;
    QPoint oldGlobalPos;
    int rightBorderX;
    int mousePressedGlobalX;
    int mousePressedGlobalY;

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();

public slots:

};

#endif // QLABELMOUSETRACKING_H
