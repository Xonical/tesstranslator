#include "bookdelegate.h"
#include "widget.h"

#include <QtWidgets>

BookDelegate::BookDelegate(QObject *parent)
    //: QSqlRelationalDelegate(parent), star(QPixmap(":images/star.png"))
: QSqlRelationalDelegate(parent), star(QPixmap("d:/star.png"))
{
}

void BookDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    //QPushButton *btn;



    if (index.column() == 2){
        QStyleOptionButton sf;
           sf.rect=option.rect;
           sf.features=QStyleOptionButton::None;


           const QAbstractItemModel *model = index.model();
           QString str = model->data(index, Qt::DisplayRole).toString();

           sf.text=(str);
           sf.state=QStyle::State_Enabled|QStyle::State_Raised;
           QApplication::style()->drawControl(QStyle::CE_PushButton,&sf,painter);

    }


    //Stern-Bewertung
    qDebug() << "QModelIndex" << index;
    qDebug() <<"QStyleOptionViewItem" << option;
    qDebug() <<"painter" << painter;


    //QPen pen = painter->pen();
//    painter->setPen(option.palette.color(QPalette::Mid));
//    painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
//    painter->drawLine(option.rect.topRight(), option.rect.bottomRight());
//    painter->setPen(pen);
/*
    if (index.column() != 7) {
        QStyleOptionViewItemV3 opt = option;
        opt.rect.adjust(0, 0, -1, -1); // since we draw the grid ourselves

        QSqlRelationalDelegate::paint(painter, opt, index);
    } else {

        //Spalte (4) in der der Stern gezeichnet wird
        const QAbstractItemModel *model = index.model();
        QPalette::ColorGroup cg = (option.state & QStyle::State_Enabled) ?
            (option.state & QStyle::State_Active) ? QPalette::Normal : QPalette::Inactive : QPalette::Disabled;

        if (option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.color(cg, QPalette::Highlight));

        int rating = model->data(index, Qt::DisplayRole).toInt();
        int width = star.width();
        int height = star.height();
        int x = option.rect.x();
        int y = option.rect.y() + (option.rect.height() / 2) - (height / 2);
        for (int i = 0; i < rating; ++i) {
            painter->drawPixmap(x, y, star);
            x += width;
        }
        drawFocus(painter, option, option.rect.adjusted(0, 0, -1, -1)); // since we draw the grid ourselves
    }

    QPen pen = painter->pen();
    painter->setPen(option.palette.color(QPalette::Mid));
    painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
    painter->drawLine(option.rect.topRight(), option.rect.bottomRight());
    painter->setPen(pen);
*/
}

QSize BookDelegate::sizeHint(const QStyleOptionViewItem &option,
                                 const QModelIndex &index) const
{
    /*
    if (index.column() == 5)
        return QSize(5 * star.width(), star.height()) + QSize(1, 1);

    return QSqlRelationalDelegate::sizeHint(option, index) + QSize(1, 1); // since we draw the grid ourselves
*/
}

bool BookDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index)
{
    /*
    if (index.column() != 5)
        return QSqlRelationalDelegate::editorEvent(event, model, option, index);

    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int stars = qBound(0, int(0.7 + qreal(mouseEvent->pos().x()
            - option.rect.x()) / star.width()), 5);
        model->setData(index, QVariant(stars));
        return false; //so that the selection can change
    }
*/
    //return true;//man kann nix ändern

//    if (index.column() != 3)
//        return QSqlRelationalDelegate::editorEvent(event, model, option, index);

//    if (event->type() == QEvent::MouseButtonPress) {
//        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

//        option

//    }



    return false;
}

QWidget *BookDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const
{
    //if (index.column() != 2)
        return QSqlRelationalDelegate::createEditor(parent, option, index);

   //Bei Klick, dann Button
    QPushButton *btn = new QPushButton(parent);
    btn->setText("Google");
    return btn;

    //if (index.column() != 3)
        //return QSqlRelationalDelegate::createEditor(parent, option, index);

    // for editing the year, return a spinbox with a range from -1000 to 2100.
    //QSpinBox *sb = new QSpinBox(parent);
    //sb->setFrame(false);
    //sb->setMaximum(2);
    //sb->setMinimum(-2);
    //return sb;

    //QPushButton *btn = new QPushButton(parent);
    //btn->setStyleSheet("background-color: rgb(022, 46, 111)");
    //return btn;
}

