//#include "__request.h"
//#include <QtNetwork>
//#include <QFile>
//#include <qmap.h>
//// init
//Request::Request()
//{
//  this->ststus = Created;

//}
//void Request::init() {
//    this->sUrl = "";
//    this->httpRequestAborted = false;
//    this->params = new QMap<QString, QString>;
//    this->status = Inited;
//    this->net = net;
//}

//void Request::addHeader(QString name, QString value){
//    this->header.insert(name.toUtf8(), value.toUtf8());
//}

//void Request::resetHeader(){
//    this->header.clear();
//}

//void Request::addParam(QString name, QString value){
//    this->params->insert(name, value);
//}

//void Request::setParams(QMap<QString,QString> *params){
//    this->params = params;
//}

//void Request::resetParams(){
//    this->params->clear();
//}

//void Request::setUrl(QString url){
//    this->sUrl = url;
//    if(this->status == Created)
//        this->init();
//    this->url.setUrl(this->sUrl);
//}

//void Request::get(QString url)
//{
//    this->setUrl(url);
//    this->get();
//}
////QNetworkRequest *Request::createRequest(){
////    QNetworkRequest *request(this->url);
////    QMap<QString, QString>::const_iterator i = this->header.constBegin();
////    while (i != this->header.constEnd()) {
////        request->setRawHeader(i.key().toUtf8(), i.value().toUtf8());
////        ++i;
////    }
////    return request;
////}

//void Request::get(){
//    if(this->status == Created)
//        this->init();

//    QNetworkRequest req(this->url);
//    QNetworkAccessManager *net = new QNetworkAccessManager();


//    connect(net , SIGNAL(finished(QNetworkReply*)), this,
//                            SLOT(finish(QNetworkReply*)));
//    net->get(req);
//    qDebug() << "dddd";
//}

//void Request::post(QString url)
//{
//    this->setUrl(url);
//    this->post();
//}

//void Request::post(){
//    if(this->status == Created)
//        this->init();

//    //incomplate
////    QNetworkRequest request = createRequest();
////    request.setHeader(QNetworkRequest::ContentTypeHeader,
////                             "application/x-www-form-urlencoded");
////    this->net.post(request,QUrlQuery().toString(QUrl::FullyEncoded).toUtf8());
//}

//void Request::finish(QNetworkReply *reply){
//    qDebug()<< "response";
//    QByteArray response;
//    int status;
//    if(reply->error() == 0){
//        response = reply->readAll();
//        status = this->Completed;
//    }else{
//        response = "";
//        status = this->Failed;
//    }
//    this->reply = reply;
//    qDebug()<< response;
//    //this->responses.push(response);
//    emit complated(response, status);
//}


