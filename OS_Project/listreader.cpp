#include "listreader.h"
#include "notifier.h"
#include <QDebug>

extern Notifier notify;

extern QList<float> BurstTime;
extern QList<float> ArrivalTime;
extern QList<float> Priority;
extern QList <QString> ScheduledId;
extern QList <float> ScheduledTime;
extern QList <float> WaitingTimePerProcess;
extern QString ProcessType;
extern bool isPreemptive;
extern int NUmberOfProcess;
extern int TimeQuantum;


ListReader::ListReader(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(configrationGenerated()),this,SLOT(setGuiList()));
    connect(this,SIGNAL(readyToLoadSimulator()),&notify,SLOT(callSimulator()));
    connect(&notify,SIGNAL(goToListReader()),this,SLOT(setSimulationList()));
}

void ListReader::setIDs(QVariantList list)
{
    QVariant list_var(list);
    processid.clear();
    foreach(QVariant v, list_var.value<QVariantList>())
    {
        processid.append(v.value<float>());
    }
}

QVariantList ListReader::readIDs()
{
    return processid;
}

QVariantList ListReader::readTimes()
{
    return processid;
}

void ListReader::setAverage(QVariantList list)
{
    QVariant list_var(list);
    processaverage.clear();
    foreach(QVariant v, list_var.value<QVariantList>())
    {
        processaverage.append(v.value<float>());
    }
}

QVariantList ListReader::readAverage()
{
    return processaverage;
}

void ListReader::setArrival(QVariantList list)
{
    QVariant list_var(list);
    arrivaltime.clear();
    foreach(QVariant v, list_var.value<QVariantList>())
    {
        arrivaltime.append(v.value<float>());
    }
}

QVariantList ListReader::readArrival()
{
    return arrivaltime;
}

void ListReader::setBurst(QVariantList list)
{
    QVariant list_var(list);
    bursttime.clear();
    foreach(QVariant v, list_var.value<QVariantList>())
    {
        bursttime.append(v.value<float>());
    }
}

QVariantList ListReader::readBurst()
{
    return bursttime;
}

void ListReader::setPriority(QVariantList list)
{
    QVariant list_var(list);
    priority.clear();
    foreach(QVariant v, list_var.value<QVariantList>())
    {
        priority.append(v.value<float>());
    }
}

QVariantList ListReader::readPriority()
{
    return priority;
}

void ListReader::setConfigrations(QString processtype, int numbers, int rrTime, bool Preemptive)
{
    processType = processtype;
    numberOfprocess = numbers;
    if(processType == "Round Robin")
        timeQuantum = rrTime;
    if(processType == "Priority" || processType == "SJF")
        preemptive = Preemptive;
}


void ListReader::setTimes(QVariantList timeList)
{
    QVariant list_var(timeList);
    processtime.clear();
    foreach(QVariant v, list_var.value<QVariantList>())
    {
        processtime.append(v.value<float>());
    }
}

void ListReader::setGuiList()
{
    QVariant list(arrivaltime);
    ArrivalTime.clear();
    BurstTime.clear();
    foreach(QVariant v, list.value<QVariantList>())
    {
        ArrivalTime.append(v.value<float>());
    }
    list = bursttime;
    foreach(QVariant v, list.value<QVariantList>())
    {
        BurstTime.append(v.value<float>());
    }
    if(this->processType == "Priority")
    {
        list = priority;
        Priority.clear();
        foreach(QVariant v, list.value<QVariantList>())
        {
            Priority.append(v.value<float>());
        }
    }
    if(this->processType == "Priority" || this->processType == "SJF")
    {
        isPreemptive = this->preemptive;
    }
    if(this->processType == "Round Robin")
    {
        TimeQuantum = this->timeQuantum;
    }
    emit readyToLoadSimulator();
}

void ListReader::setSimulationList()
{
    processid.clear();
    processtime.clear();
    processaverage.clear();
    for(int i = 0 ; i < ScheduledId.size(); i++)
    {
        qDebug() << "entered";
        processid.append(ScheduledId[i]);
        processtime.append(ScheduledTime[i]);
        processaverage.append(WaitingTimePerProcess[i]);
        qDebug() << processid[i] << processtime[i];
    }
}
