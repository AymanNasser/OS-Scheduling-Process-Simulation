#ifndef LISTREADER_H
#define LISTREADER_H

#include <QObject>
#include <QVariantList>

class ListReader : public QObject
{
    Q_OBJECT
public:
    explicit ListReader(QObject *parent = nullptr);

    Q_PROPERTY(QVariantList BurstTime READ readBurst WRITE setBurst)
    Q_PROPERTY(QVariantList ArrivalTime READ readArrival WRITE setArrival)
    Q_PROPERTY(QVariantList Priority READ readPriority WRITE setPriority)

    Q_INVOKABLE void setArrival(QVariantList);
    Q_INVOKABLE QVariantList readArrival();
    Q_INVOKABLE void setBurst(QVariantList);
    Q_INVOKABLE QVariantList readBurst();
    Q_INVOKABLE void setPriority(QVariantList);
    Q_INVOKABLE QVariantList readPriority();

    Q_INVOKABLE void setConfigrations(QString processtype,int numbers,int rrTime,bool preemptive);

private:
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
};

#endif // LISTREADER_H
