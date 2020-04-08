#include "notifier.h"

Notifier::Notifier(QObject *parent) : QObject(parent)
{

}

void Notifier::callSimulator()
{
    emit qmlGenerated();
}
