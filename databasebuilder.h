#ifndef DATABASECREATOR_H
#define DATABASECREATOR_H

#include <QObject>

class databasecreator : public QObject
{
    Q_OBJECT
public:
    explicit databasecreator(QObject *parent = 0);
    ~databasecreator();

signals:

public slots:
};

#endif // DATABASECREATOR_H
