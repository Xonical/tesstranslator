#ifndef LANGUAGEHELPER_H
#define LANGUAGEHELPER_H

#include <QObject>

class LanguageHelper : public QObject
{
    Q_OBJECT
public:
    explicit LanguageHelper(QObject *parent = 0);

    enum Languages
    {
       English,
       German
    };

    ~LanguageHelper();

signals:

public slots:
};

#endif // LANGUAGEHELPER_H
