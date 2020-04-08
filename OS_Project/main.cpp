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

        QGuiApplication app(argc,argv);

        IDE ide(&app,argc,argv);

        return app.exec();
}
