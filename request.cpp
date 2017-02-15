#include "request.h"
#include <qmap.h>
#include <QtNetwork>
Request::Request(QObject *parent) : QObject(parent)
{
    this->status = Created;
    this->resetHeader();
    this->resetParams();
    QNetworkAccessManager *network = new QNetworkAccessManager(parent);

    connect(network, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(finish(QNetworkReply*)));

    this->network = network;
    this->resetHeader();

}
void Request::addHeader(QString name, QString value)
{

    this->request->setRawHeader(name.toUtf8(), value.toUtf8());
}

void Request::addHeaders(QMap<QString,QString> *headers)
{
    QMapIterator<QString, QString> i(*headers);
    while (i.hasNext()) {
        i.next();
        this->addHeader( i.key() , i.value());
    }
}

void Request::addParam(QString name, QString value)
{
    this->query.addQueryItem(name,value);
}

void Request::setParams(QMap<QString,QString> *params)
{
    QMapIterator<QString, QString> i(*params);
    while (i.hasNext()) {
        i.next();
        this->addParam( i.key() , i.value());
    }
}

void Request::setUrl(QString url){
    this->url.setUrl(url);

    this->request->setUrl(this->url);
}

void Request::get(QString url)
{
    this->status = Sending;
    this->setUrl(url);

    this->replay = this->network->get(*this->request);
}

void Request::post(QString url)
{
    this->status = Sending;
    this->setUrl(url);
    this->query.addQueryItem("foo", "bar");
    this->request->setHeader(QNetworkRequest::ContentTypeHeader,
        "application/x-www-form-urlencoded");

    this->replay = this->network->post(*this->request, this->query.toString(QUrl::FullyEncoded).toUtf8());
}

void Request::resetHeader()
{
    this->request = new QNetworkRequest(QUrl("http://localhost"));
}

void Request::resetParams()
{
    this->params = new QMap<QString, QString>;

}
void Request::abort(){
    if(this->status == Sending){
        this->status = Aborted;
        this->replay->abort();
    }
}

void Request::finish(QNetworkReply *replay){
    if(replay->error() == 0){
        this->status = Compate;
        this->lastResp = replay->readAll();
    }else{
        this->lastResp = "";
        this->status = Failed;
    }
    emit complated(this->lastResp, this->status);
}
