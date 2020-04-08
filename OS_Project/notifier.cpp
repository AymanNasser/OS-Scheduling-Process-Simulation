#include "notifier.h"

Notifier::Notifier(QObject *parent) : QObject(parent)
{

}

void Notifier::callSimulator()
{
    emit qmlGenerated();
}

void Notifier::emitListReader()
{
    emit goToListReader();
}
