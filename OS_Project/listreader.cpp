#include "listreader.h"
#include "notifier.h"
#include <QDebug>

extern Notifier notify;

extern QList<float> BurstTime;
extern QList<float> ArrivalTime;
extern QList<float> Priority;
extern QString ProcessType;
extern bool isPreemptive;
extern int NUmberOfProcess;
extern int TimeQuantum;


ListReader::ListReader(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(configrationGenerated()),this,SLOT(copyList()));
    connect(this,SIGNAL(readyToLoadSimulator()),&notify,SLOT(callSimulator()));
}

void ListReader::setIDs(QVariantList)
{

}

QVariantList ListReader::readIDs()
{
    return processid;
}

QVariantList ListReader::readTimes()
{
    return processid;
}

void ListReader::setAverage(QVariantList)
{

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

}

void ListReader::copyList()
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
