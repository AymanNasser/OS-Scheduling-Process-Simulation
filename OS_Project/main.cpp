#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QList>
#include <QIcon>
#include "listreader.h"
#include "notifier.h"
#include "ide.h"

Notifier notify;

QList<qreal> BurstTime;
QList<qreal> ArrivalTime;
QList<unsigned int> Priority;
QList <QString> ScheduledId;
QList <qreal> ScheduledTime;
QList <qreal> WaitingTimePerProcess;
QString ProcessType;
bool isPreemptive;
int NUmberOfProcess;
int TimeQuantum;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc,argv);
    app.setWindowIcon(QIcon(":/images/icons/process_manager.png"));

    IDE ide(&app,argc,argv);

    return app.exec();
}
