#include "ide.h"
#include "notifier.h"
#include "process.h"
#include <QQuickWindow>

extern Notifier notify;

IDE::IDE(QGuiApplication* mainApp,int argc, char *argv[],QObject* parent) : QObject(parent)
{
    interfaceEngine = new QQmlApplicationEngine;
    app = new QGuiApplication(argc,argv);
    app = mainApp;
    const QUrl urlInterface(QStringLiteral("qrc:/main_interface.qml"));

    qmlRegisterType<ListReader>("QList",1,0,"ListQML");

    interfaceEngine->load(urlInterface);

    connect(&notify,SIGNAL(qmlGenerated()),this,SLOT(loadSimulator()));
    connect(this,SIGNAL(loadSimulatorData()),&notify,SLOT(emitListReader()));
}

void IDE::loadSimulator()
{
    if(simulatorEngine == nullptr)
    {
        simulatorEngine = new QQmlApplicationEngine;
        emit loadSimulatorData();
        Process process;
        const QUrl urlSimulator(QStringLiteral("qrc:/main_simulator.qml"));
        simulatorEngine->load(urlSimulator);
    }
    else if(simulatorEngine != nullptr)
    {
        for(int i = 0; i < simulatorEngine->rootObjects().size();i++)
        {
            QObject* object = simulatorEngine->rootObjects()[i];
            QQuickWindow* runningEditor = qobject_cast<QQuickWindow*>(object);
            runningEditor->close();
        }
        const QUrl urlSimulator(QStringLiteral("qrc:/main_simulator.qml"));
        simulatorEngine->load(urlSimulator);
    }
}
