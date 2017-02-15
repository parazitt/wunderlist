#ifndef REQUEST_H
#define REQUEST_H
#include <QMap>
#include <QObject>
#include <QtNetwork>
class Request : public QObject
{
    Q_OBJECT
public:
    explicit Request(QObject *parent = 0);
    void addHeader(QString name, QString value);
    void addHeaders(QMap<QString,QString> *params);
    void addParam(QString name, QString value);
    void setUrl(QString url);
    void setParams(QMap<QString,QString> *params);
    void get(QString url);
    void post(QString url);
    void abort();
    void resetHeader();
    void resetParams();
    enum {
        Created = 0,
        Sending = 1,
        Failed  = 2,
        Aborted = 3,
        Compate = 99
    };
signals:
void complated(QString respons, int status);
public slots:
    void finish(QNetworkReply *replay);
private:
    int status;
    QMap<QString, QString> *headers;
    QMap<QString, QString> *params;
    QNetworkAccessManager *network;
    QNetworkRequest *request;
    QNetworkReply *replay;
    QString lastResp;
    QUrlQuery query;
    QUrl url;
};

#endif // REQUEST_H
