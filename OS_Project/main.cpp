#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "process.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    Process p(3,"FCFS");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
