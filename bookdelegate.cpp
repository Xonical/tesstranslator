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

    if (index.column() == 4) {
        QVariant value = index.model()->data(index, Qt::UserRole);
//        if (!isSupportedType(value.type())) {
//            QStyleOptionViewItem myOption = option;
//            myOption.state &= ~QStyle::State_Enabled;
//            QItemDelegate::paint(painter, myOption, index);
            return;
//        }
    }

    QItemDelegate::paint(painter, option, index);



//    if (index.column() == 4){
//        QStyleOptionButton sf;
//           sf.rect=option.rect;
//           sf.features=QStyleOptionButton::None;
//           const QAbstractItemModel *model = index.model();
//           //Hole Feld "link" aus db
//           //QString str = model->data(index, Qt::DisplayRole).toString();
//           sf.text=("Foo");
//           sf.state=QStyle::State_Enabled|QStyle::State_Raised;
//           QApplication::style()->drawControl(QStyle::CE_PushButton,&sf,painter);
//           QApplication::style()->drawControl(QStyle::CE_PushButton,&sf,painter);
//           //
//    }else{
//        QSqlRelationalDelegate::paint(painter, option, index);
//    }

//    QStyleOptionViewItemV3 opt = option;
//    opt.rect.adjust(0, 0, -1, -1); // since we draw the grid ourselves
//    drawFocus(painter, option, option.rect.adjusted(0, 0, -1, -1)); // since we draw the grid ourselves




   //
   // QPen pen = painter->pen();
//    painter->setPen(option.palette.color(QPalette::Mid));
//    painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
//    painter->drawLine(option.rect.topRight(), option.rect.bottomRight());
    //painter->setPen(pen);

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
*/

    qDebug() <<"sizeHint";
    return QSqlRelationalDelegate::sizeHint(option, index) + QSize(1, 1); // since we draw the grid ourselves

}

bool BookDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index)
{
    if (index.column() != 4){

        //gg
//        if (event->type() == QEvent::MouseButtonPress) {
//            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
//            int stars = qBound(0, int(0.7 + qreal(mouseEvent->pos().x()
//                - option.rect.x()) / star.width()), 5);
//            model->setData(index, QVariant(stars));
//            return false; //so that the selection can change
//        }
        return false;
    }else{
        return true;
        // return QSqlRelationalDelegate::editorEvent(event, model, option, index);
    }


//    if (event->type() == QEvent::MouseButtonPress) {
//        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);


        //model->setData(index, QVariant(stars));
        //return false; //so that the selection can change

    //return true;//man kann nix ändern
}

QWidget *BookDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const
{
     // We don't want edit the link, just click
     if (index.column() != 4){

     }else{
         //return QSqlRelationalDelegate::createEditor(parent, option, index);
         //return 0;

     }
 return QSqlRelationalDelegate::createEditor(parent, option, index);

    //if (index.column() != 2)


   //Bei Klick, dann Button
//    QPushButton *btn = new QPushButton(parent);
//    btn->setText("Google");
//    return btn;

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

