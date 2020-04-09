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
    Q_OBJECT
private:
    unsigned int numOfProcesses;
    unsigned int timeQuantum;
    QString algorithmType;
    bool preemptive;

    QList <qreal> burstTime ;
    QList <qreal> arrivalTime ;
    QList <QString> processName;

    QList <unsigned int> priority;

    /* Temp list for SJF algorithm processes indexing */
    QList <unsigned int> index;


    /* QML simulation lists */
    QList <QString> toQmlScheduledId;
    QList <qreal> toQmlScheduledTime;
    QList <qreal> toQmlwaitingTimePerProcess;


private:
    void handleFCFS();
    void handleSJF();
    void handleRoundRobin();
    void handlePriority();
    void SJF_swapLists();
    void handleScheduling();
    void SJF_nonPreemptiveOperation();
    void SJF_preemptiveOperation();
    void RR_operation();
    void prioritySorting();
    qreal sumBusttime();
    int processTakePriority(qreal time, unsigned int currentProcess);


public:
    Process();

    QString getAlgorithmType();

    QList <QString> getScheduledProcessId();
    QList <qreal> getScheduledProcessBurstTime();
    QList <qreal> getSchduledProcessWaitingTime();


    qreal calcOverAllAverageWaitingTime();



signals:

public slots:
};

#endif // PROCESS_H
