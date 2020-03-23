#ifndef PROCESS_H
#define PROCESS_H


#include <QObject>
#include <QQuickItem>
#include <bits/stdc++.h>
#include <QString>
#include <QList>
class Process : public QObject
{

private:
    unsigned int numOfProcesses;
    QString algorithmType;
    bool preemptive;
    QList <qreal> averageWaitingTime;
    QList <unsigned int> burstTime;
    QList <unsigned int> arrivalTime;
    QList <unsigned int> priority;




    Q_OBJECT
public:
    Process(unsigned int a_processesNum, QString a_type);

    QString getAlgorithmType();
    QList <unsigned int> getBurstTime();
    QList <unsigned int> getArrivalTime();
    QList <unsigned int> getPriority();
    void handleScheduling();

    void handleFCFS();
    void handleSJF();
    void handleRoundRobin();
    void handlePriority();
    float calcOverAllAverageWaitingTime();







signals:

public slots:
};

#endif // PROCESS_H
