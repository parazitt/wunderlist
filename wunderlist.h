#ifndef WUNDERLIST_H
#define WUNDERLIST_H
#include <QtNetwork>
#include <QObject>

class Wunderlist : public QObject
{
    Q_OBJECT
public:
    explicit Wunderlist(QObject *parent = 0);

signals:

public slots:
    void finish(QNetworkReply* reply);
    void print(QString respons, int status);
    int login(QString user, QString password);

    void     networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible);

};

#endif // WUNDERLIST_H


