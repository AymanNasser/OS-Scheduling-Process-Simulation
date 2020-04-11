#ifndef IDE_H
#define IDE_H

#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QObject>
#include <QList>
#include "qqml.h"
#include "listreader.h"


class IDE : public QObject
{
    Q_OBJECT
public:
    explicit IDE(QGuiApplication*,int argc, char *argv[],QObject *parent = nullptr);

private:
    QQmlApplicationEngine* interfaceEngine;
    QQmlApplicationEngine* simulatorEngine = nullptr;
    QGuiApplication* app;
    void setSimulatorList();

private slots:
    void loadSimulator();
    void loadSimulatorWindow();
signals:
    void loadSimulatorData();

};

#endif // IDE_H
