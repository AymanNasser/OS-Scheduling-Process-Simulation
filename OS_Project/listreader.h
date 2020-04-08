#ifndef LISTREADER_H
#define LISTREADER_H

#include <QObject>
#include <QVariantList>

class ListReader : public QObject
{
    Q_OBJECT
public:
    explicit ListReader(QObject *parent = nullptr);
    Q_PROPERTY(QVariantList ProcessID READ readIDs WRITE setIDs)
    Q_PROPERTY(QVariantList ProcessTime READ readTimes WRITE setTimes)
    Q_PROPERTY(QVariantList AverageTime READ readAverage WRITE setAverage)
    Q_PROPERTY(QVariantList BurstTime READ readBurst WRITE setBurst)
    Q_PROPERTY(QVariantList ArrivalTime READ readArrival WRITE setArrival)
    Q_PROPERTY(QVariantList Priority READ readPriority WRITE setPriority)
    Q_INVOKABLE void setIDs(QVariantList);
    QVariantList readIDs();
    Q_INVOKABLE void setTimes(QVariantList);
    QVariantList readTimes();
    Q_INVOKABLE void setAverage(QVariantList);
    QVariantList readAverage();

    Q_INVOKABLE void setArrival(QVariantList);
    QVariantList readArrival();
    Q_INVOKABLE void setBurst(QVariantList);
    QVariantList readBurst();
    Q_INVOKABLE void setPriority(QVariantList);
    QVariantList readPriority();

    Q_INVOKABLE void setConfigrations(QString processtype,int numbers,int rrTime,bool preemptive);

private:
    QVariantList processid;
    QVariantList processtime;
    QVariantList processaverage;
    QVariantList bursttime;
    QVariantList arrivaltime;
    QVariantList priority;
    int numberOfprocess;
    QString processType;
    bool preemptive;
    int timeQuantum;
signals:
    void configrationGenerated();
    Q_INVOKABLE void readyToLoadSimulator();

private slots:
    void setGuiList();
    void setSimulationList();

};

#endif // LISTREADER_H
