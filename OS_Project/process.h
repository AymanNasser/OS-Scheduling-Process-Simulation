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

    QList <unsigned int> burstTime = {3,4,2,4,1};
    QList <unsigned int> arrivalTime = {3,1,6,5,5};
    QList <unsigned int> priority;

    /* Temp list for SJF algorithm processes indexing */
    QList <unsigned int> index;


    /* QML simulation lists */
    QList <QString> toQmlScheduledId;
    QList <unsigned int> toQmlScheduledTime;
    QList <unsigned int> toQmlwaitingTimePerProcess;


    Q_OBJECT

private:
    void handleFCFS();
    void handleSJF();
    void handleRoundRobin();
    void handlePriority();
    void SJF_swapLists();
    void handleScheduling();
    void SJF_nonPreemptiveOperation();


public:
    Process(unsigned int a_processesNum, QString a_type);

    QString getAlgorithmType();

    QList <QString> getScheduledProcessId();
    QList <unsigned int> getScheduledProcessBurstTime();
    QList <unsigned int> getSchduledProcessWaitingTime();


    qreal calcOverAllAverageWaitingTime();







signals:

public slots:
};

#endif // PROCESS_H
