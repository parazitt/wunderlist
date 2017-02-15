#include "wunderlist.h"
#include "request.h"
Wunderlist::Wunderlist(QObject *parent) : QObject(parent)
{

}

int Wunderlist::login(QString user, QString password){
//    QNetworkAccessManager *NA = new QNetworkAccessManager();

//    connect(NA , SIGNAL(finished(QNetworkReply*)), this,
//                        SLOT(finish(QNetworkReply*)));
//    connect(NA , SIGNAL(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)),
//            this, SLOT(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)));

//    QNetworkRequest req(
//                QUrl("https://a.wunderlist.com/api/v1/user")
//                );
//    QUrlQuery query;
//    req.setRawHeader("X-Access-Token", "c15c7f3709e633826671b2001530819df39938398a0ea05baa04b4e4e9d0");
//    req.setRawHeader("X-Client-ID", "d67692c8be291e9ca8a6");
//    //req.setHeader(QNetworkRequest::ContentTypeHeader,
//      //  "application/x-www-form-urlencoded");
//    //NA->post(req, query.toString(QUrl::FullyEncoded).toUtf8());
//    //NA->get(req);
    Request *re = new Request();
    re->addHeader("X-Access-Token", "c15c7f3709e633826671b2001530819df39938398a0ea05baa04b4e4e9d0");
    re->addHeader("X-Client-ID", "d67692c8be291e9ca8a6");
    re->get("https://a.wunderlist.com/api/v1/lists");
    connect(re, SIGNAL(complated(QString,int)),
            this , SLOT(print(QString,int)));
}
void Wunderlist::print(QString respons, int status){
    qDebug() << respons;
}

void Wunderlist::finish(QNetworkReply *reply){
    qDebug() << "fuck";
    qDebug() << reply->readAll();
}
void Wunderlist::networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible){
    switch (accessible) {
    case 1:
        qDebug() << "retrieve header";
        break;
    case 2:
        qDebug() << "rsending";
        break;
    case 3:
        qDebug() << "uploading";
        break;
    case 4:
        qDebug() << "ok";
        break;
    case 5:
        qDebug() << "complate";
        break;
    case 6:
        qDebug() << "finished";
        break;
    default:
        qDebug() << "unkonwn";
        break;
    }
}
