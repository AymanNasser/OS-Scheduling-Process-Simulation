#ifndef PROCESS_H
#define PROCESS_H


#include <QObject>
#include <QQuickItem>
#include <QString>
#include <QList>

#include <QtAlgorithms>
#include <QVector>

class Process : public QObject
{

private:
    unsigned int numOfProcesses;
    QString algorithmType;
    bool preemptive;
    QList <qreal> averageWaitingTime;
    QList <unsigned int> burstTime = {3,4,2,4,1};
    QList <unsigned int> arrivalTime = {3,1,6,5,5};
    QList <unsigned int> priority;
    QList <QString> processName;
    QList <unsigned int> index;
    QList <unsigned int> waitingTimePerProcess;

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
    qreal calcOverAllAverageWaitingTime();







signals:

public slots:
};

#endif // PROCESS_H
