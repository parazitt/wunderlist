#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "wunderlist.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Wunderlist r;
    r.login("","");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
