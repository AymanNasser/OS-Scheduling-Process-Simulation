#ifndef LISTREADER_H
#define LISTREADER_H

#include <QObject>
#include <QVariantList>
#include <QList>

class ListReader : public QObject
{
    Q_OBJECT
public:
    explicit ListReader(QObject *parent = nullptr);

    Q_PROPERTY(QVariantList ProcessID READ readIDs WRITE setIDs)
    Q_PROPERTY(QVariantList ProcessTime READ readTimes WRITE setTimes)
    Q_PROPERTY(QList<qreal> AverageTime READ readAverage WRITE setAverage)

    Q_PROPERTY(QVariantList BurstTime READ readBurst WRITE setBurst)
    Q_PROPERTY(QVariantList ArrivalTime READ readArrival WRITE setArrival)
    Q_PROPERTY(QVariantList Priority READ readPriority WRITE setPriority)

    Q_INVOKABLE void setIDs(QVariantList);
    QVariantList readIDs();
    Q_INVOKABLE void setTimes(QVariantList);
    QVariantList readTimes();
    void setAverage(QList<qreal>);
    QList<qreal> readAverage();

    Q_INVOKABLE int idsLength();
    Q_INVOKABLE QString readIDitem(int);
    Q_INVOKABLE int timeLength();
    Q_INVOKABLE qreal readTimeitem(int);
    Q_INVOKABLE int averageLength();
    Q_INVOKABLE qreal readAverageitem(int);

    Q_INVOKABLE void setArrival(QVariantList);
    Q_INVOKABLE QVariantList readArrival();
    Q_INVOKABLE void setBurst(QVariantList);
    Q_INVOKABLE QVariantList readBurst();
    Q_INVOKABLE void setPriority(QVariantList);
    Q_INVOKABLE QVariantList readPriority();

    Q_INVOKABLE void setConfigrations(QString processtype,int numbers,int rrTime,bool preemptive);

private:
    QVariantList processid;
    QVariantList processtime;
    QList<qreal> processaverage;
    QVariantList bursttime;
    QVariantList arrivaltime;
    QVariantList priority;
    int numberOfprocess;
    QString processType;
    bool preemptive;
    int timeQuantum;
signals:
    void configrationGenerated();
    void allProcessfinished();
    Q_INVOKABLE void readyToLoadSimulator();

private slots:
    void setGuiList();
    void setSimulationList();

};

#endif // LISTREADER_H
