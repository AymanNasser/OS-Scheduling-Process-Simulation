#ifndef IDE_H
#define IDE_H

#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QObject>
#include <QList>
#include <QVariant>
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
    void loadSimulatorWindow();

private slots:
    void loadSimulator();


};

#endif // IDE_H
