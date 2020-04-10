#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <QObject>

class Notifier : public QObject
{
   Q_OBJECT
public:
    Notifier(QObject *parent = nullptr);

signals:
    void qmlGenerated();
    void goToListReader();
    void allowIDEtogenerateQML();
public slots:
    void callSimulator();
    void emitListReader();
    void listcopyglobaldata();

};

#endif // NOTIFIER_H
