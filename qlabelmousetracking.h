#ifndef QLABELMOUSETRACKING_H
#define QLABELMOUSETRACKING_H

#include <QLabel>
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

class QLabelMouseTracking : public QLabel
{
    Q_OBJECT
public:
    explicit QLabelMouseTracking(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *ev);

    int x,y;

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();

public slots:

};

#endif // QLABELMOUSETRACKING_H
