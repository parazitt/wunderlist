//#ifndef REQUEST_H
//#define REQUEST_H

//#include <QtNetwork>
//#include <QObject>
//#include <qmap.h>

//class Request : public QObject
//{
//    Q_OBJECT
//public slots:
//    void finish(QNetworkReply* reply);
//public:
//    Request();
//    void init();
//    void addHeader(QString name, QString value);
//    void addParam(QString name, QString value);
//    void setParams(QMap<QString,QString> *params);
//    void setUrl(QString url);
//    void get(QString url);
//    void post(QString url);
//    void get();
//    void post();
//    void resetHeader();
//    void resetParams();
//    enum {
//        Created = 0,
//        Inited =  1,
//        Requesting = 2,
//        Abort = 3,
//        Failed = 4,
//        Completed = 99,
//    };
//signals:
//    void complated(QString response, int status);
//private:
//  int status;
//  QString sUrl;
//  QUrl url;
//  int ststus;
//  QNetworkAccessManager *net;
//  QNetworkReply *reply;
//  bool httpRequestAborted;
//  QMap<QString,QString> *params;
//  QMap<QString,QString> header;
//};

//#endif // REQUEST_H
