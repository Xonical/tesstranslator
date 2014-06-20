#ifndef HISTORYDELEGATE_H
#define HISTORYDELEGATE_H

#include <QModelIndex>
#include <QPixmap>
#include <QSize>
#include <QSqlRelationalDelegate>
#include<QDebug>
#include <QPushButton>
#include<QWebView>
#include <QUrl>
#include <translator.h>

QT_FORWARD_DECLARE_CLASS(QPainter)

class HistoryDelegate : public QSqlRelationalDelegate
{
public:
    HistoryDelegate(QObject *parent, Translator *translator);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index);



private:
    QPushButton *btn;
    Translator *translator;
};

#endif
