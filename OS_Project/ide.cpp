#include "ide.h"
#include "notifier.h"
#include "process.h"
#include <QQuickWindow>

extern Notifier notify;

extern QList <QString> ScheduledId;
extern QList <qreal> ScheduledTime;
extern QList <qreal> WaitingTimePerProcess;

IDE::IDE(QGuiApplication* mainApp,int argc, char *argv[],QObject* parent) : QObject(parent)
{
    interfaceEngine = new QQmlApplicationEngine;
    app = new QGuiApplication(argc,argv);
    app = mainApp;
    const QUrl urlInterface(QStringLiteral("qrc:/main_interface.qml"));

    qmlRegisterType<ListReader>("QList",1,0,"ListQML");

    interfaceEngine->load(urlInterface);

    connect(&notify,SIGNAL(qmlGenerated()),this,SLOT(loadSimulator()));
    //connect(&notify,SIGNAL(allowIDEtogenerateQML()),this,SLOT(loadSimulatorWindow()));
    connect(this,SIGNAL(loadSimulatorData()),&notify,SLOT(emitListReader()));
}

void IDE::loadSimulator()
{
    if(simulatorEngine == nullptr)
    {
        Process process;
        simulatorEngine = new QQmlApplicationEngine;
        emit loadSimulatorData();
        this->loadSimulatorWindow();
    }
    else if(simulatorEngine != nullptr)
    {
        Process process;
        for(int i = 0; i < simulatorEngine->rootObjects().size();i++)
        {
            QObject* object = simulatorEngine->rootObjects()[i];
            QQuickWindow* runningEditor = qobject_cast<QQuickWindow*>(object);
            runningEditor->close();
        }
        emit loadSimulatorData();
        this->loadSimulatorWindow();
    }
}

void IDE::loadSimulatorWindow()
{
    QQmlComponent component(simulatorEngine, QUrl(QStringLiteral("qrc:/main_simulator.qml")));
    QObject *object = component.create();
    QVariantList list_id,list_time;
    for(int i = 0 ; i < ScheduledId.size(); i++)
    {
        list_id.append(ScheduledId[i]);
    }
    for(int i = 0 ; i < ScheduledTime.size(); i++)
    {
        list_time.append(ScheduledTime[i]);
    }
    QVariant id(list_id),schedualtime(list_time);
    QMetaObject::invokeMethod(object, "setLists",Q_ARG(QVariant, id),Q_ARG(QVariant, schedualtime));

    delete object;
    const QUrl urlSimulator(QStringLiteral("qrc:/main_simulator.qml"));
    simulatorEngine->load(urlSimulator);
}
