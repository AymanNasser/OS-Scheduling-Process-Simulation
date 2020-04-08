#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include "listreader.h"
#include "notifier.h"
#include "ide.h"

Notifier notify;

QList<float> BurstTime;
QList<float> ArrivalTime;
QList<float> Priority;
QString ProcessType;
bool isPreemptive;
int NUmberOfProcess;
int TimeQuantum;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

<<<<<<< HEAD
        QGuiApplication app(argc,argv);
=======
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    Process p(3,"FCFS");
>>>>>>> 2d81f8c5a25aa39d934c0066821ca16ce95e9e9e

        IDE ide(&app,argc,argv);

        return app.exec();
}
