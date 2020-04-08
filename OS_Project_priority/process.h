#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

class Process : public QObject
{
    Q_OBJECT


private:
    unsigned int numOfProcesses;
    QString algorithmType;
    bool preemptive;
    QList <qreal> averageWaitingTime;
    QList <float> burstTime;
    QList <float> arrivalTime;
    QList <unsigned int> priority;
    QList <float> time;
    QList <QString> process_name;
    QList <QString> processName;
    QMap <QString, unsigned int> scheduledProcesses;
    void prioritySorting();
    float sumBusttime();
    int processTakePriority(float time, unsigned int currentProcess);

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
