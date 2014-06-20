#include "bookdelegate.h"
#include "imagecrop.h"

#include <QtWidgets>

BookDelegate::BookDelegate(QObject *parent)
    //: QSqlRelationalDelegate(parent), star(QPixmap(":images/star.png"))
: QSqlRelationalDelegate(parent)
{
}

void BookDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    if (index.column() == 4) {
        QVariant value = index.model()->data(index, Qt::UserRole);

                QStyleOptionButton sf;
                   sf.rect=option.rect;
                   sf.features=QStyleOptionButton::None;
                   const QAbstractItemModel *model = index.model();
                   //Hole Feld "link" aus db
                   //QString str = model->data(index, Qt::DisplayRole).toString();
                   sf.text=("Foo");
                   sf.state=QStyle::State_Enabled|QStyle::State_Raised;
                   QApplication::style()->drawControl(QStyle::CE_PushButton,&sf,painter);
                   QApplication::style()->drawControl(QStyle::CE_PushButton,&sf,painter);
        return;
    }
    QItemDelegate::paint(painter, option, index);
}

QSize BookDelegate::sizeHint(const QStyleOptionViewItem &option,
                                 const QModelIndex &index) const
{

    return QSqlRelationalDelegate::sizeHint(option, index) + QSize(1, 1); // since we draw the grid ourselves

}

bool BookDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index)
{
    if (index.column() != 4){



        return false; //so that the selection can change

    }else{



        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

            QVariant originalValue = index.model()->data(index, Qt::DisplayRole);
            qDebug() <<"Linktyp:  " << originalValue.type() << " steht: " << originalValue;
        }






        return true;
    }
}

