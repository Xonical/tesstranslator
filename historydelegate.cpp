#include "historydelegate.h"
#include "imagecrop.h"

#include <QtWidgets>

HistoryDelegate::HistoryDelegate(QObject *parent, Translator *translator)
    //: QSqlRelationalDelegate(parent), star(QPixmap(":images/star.png"))
: QSqlRelationalDelegate(parent)
{
    this->translator = translator;
}

void HistoryDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    if (index.column() == 4) {
        QVariant value = index.model()->data(index, Qt::UserRole);

                QStyleOptionButton sf;
                   sf.rect=option.rect;
                   sf.features=QStyleOptionButton::None;
                   const QAbstractItemModel *model = index.model();
                   sf.text=("go to");

                   sf.state=QStyle::State_Enabled|QStyle::State_Raised;
                   QApplication::style()->drawControl(QStyle::CE_PushButton,&sf,painter);
                   QApplication::style()->drawControl(QStyle::CE_PushButton,&sf,painter);
        return;
    }
    QItemDelegate::paint(painter, option, index);
}

QSize HistoryDelegate::sizeHint(const QStyleOptionViewItem &option,
                                 const QModelIndex &index) const
{

    return QSqlRelationalDelegate::sizeHint(option, index) + QSize(1, 1); // since we draw the grid ourselves

}

bool HistoryDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
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

            qDebug() << "Parent " << this->parent()->metaObject()->className();

//            //QWebView *webView  = qobject_cast<QWebView *>(this->parent());
//             QTableView *webView  = qobject_cast<QTableView *>(this->parent());

//            qDebug() << "Parent webView "  << webView->parent()->metaObject()->className()
//             qDebug() << "Parent model "  <<       model->parent()->metaObject()->className();
           // webView->setUrl(QUrl(originalValue.toString()));
            this->translator->setUrlFromButton(originalValue.toString());
        }






        return true;
    }
}

