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
    unsigned int timeQuantum;
    QString algorithmType;
    bool preemptive;

<<<<<<< HEAD
    QList <unsigned int> burstTime = {8,4,9,5};
    QList <unsigned int> arrivalTime = {0,1,2,3};
    QList <QString> processName;
=======
    QList <unsigned int> burstTime = {24,3,3};
    QList <unsigned int> arrivalTime = {0,0,0};

>>>>>>> 2d81f8c5a25aa39d934c0066821ca16ce95e9e9e
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
    void SJF_preemptiveOperation();
    void RR_operation();
    void prioritySorting();
    float sumBusttime();
    int processTakePriority(float time, unsigned int currentProcess);


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
