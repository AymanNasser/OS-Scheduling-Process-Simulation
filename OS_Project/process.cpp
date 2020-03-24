#include "process.h"




Process::Process(unsigned int a_processesNum, QString a_type)
{
    this->numOfProcesses = a_processesNum;
    this->algorithmType = a_type;


    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        index.append(var);
        toQmlwaitingTimePerProcess.append(0);
    }

    this->preemptive = 0;

    handleScheduling();
}


void Process::SJF_swapLists(){

    for (unsigned int i = 0; i < this->numOfProcesses -1 ; ++i) {
        for (unsigned int j = 0 ; j < this->numOfProcesses -1 - i; ++j) {
            if(this->burstTime[j] > burstTime[j+1])
            {
                qSwap(arrivalTime[j],arrivalTime[j+1]);
                qSwap(burstTime[j],burstTime[j+1]);
                qSwap(index[j],index[j+1]);

            }
        }
    }
}

void Process::SJF_nonPreemptiveOperation(){

    /* Calculating processes terminating time == > overAllBurstTime then
     * sorting the processes burst time in ascending order according to
     * SJF algorithm
    */
    unsigned int tick = 0 ,ite;
    bool unMatchedProcessPerTick = true;
    unsigned int overAllBurstTime = 0;

    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        overAllBurstTime+= burstTime[var];
    }


    /* Didn't support if the arrival time is more than the total processes burst time*/
    while(tick < overAllBurstTime){
        for (ite = 0; ite < this->numOfProcesses ; ++ite) {
            if(arrivalTime[ite] <= tick && burstTime[ite] !=0 )
            {
                toQmlScheduledId.append(QString("P" + QString(index[ite])));

                toQmlwaitingTimePerProcess[ite] = tick - arrivalTime[ite];
                tick+= burstTime[ite];
                burstTime[ite] = 0;
                /* This line changes the the appended time to list
                *  appending (tick) ==> getting when the task is started
                *  appending (tick -1) ==> getting when the task is terminated
                */
                toQmlScheduledTime.append(tick);
                unMatchedProcessPerTick = false;

                break;
            }
            else
            {
                unMatchedProcessPerTick = true;
            }

        }

        if(unMatchedProcessPerTick)
        {
            tick++;
            toQmlScheduledId.append("IDEAL");
            toQmlScheduledTime.append(tick);
        }
    }

}




QString Process::getAlgorithmType()
{
    return  this->algorithmType;
}

QList<unsigned int> Process::getScheduledProcessBurstTime()
{
    return this->toQmlScheduledTime;
}

QList<unsigned int> Process::getSchduledProcessWaitingTime()
{
    return this->toQmlwaitingTimePerProcess;
}

QList<QString> Process::getScheduledProcessId()
{
    return this->toQmlScheduledId;
}

void Process::handleScheduling()
{
    if(this-> algorithmType == "FCFS")
    {
         handleFCFS();
    }
    else if(this-> algorithmType == "SJF")
    {
         handleSJF();


    }
    else if(this->algorithmType == "RoundRobin")
    {
        handleRoundRobin();

    }
    else if(this->algorithmType == "Priority")
    {
        handlePriority();
    }
    else{}
}

void Process::handleFCFS()
{

}

void Process::handleSJF()
{
    if(! (this->preemptive) )
    {
        SJF_swapLists();
        SJF_nonPreemptiveOperation();
        qSort(toQmlwaitingTimePerProcess);
    }

    else
    {

    }
}

void Process::handleRoundRobin()
{

}

void Process::handlePriority()
{

}

qreal Process::calcOverAllAverageWaitingTime()
{
    qreal temp = 0;
    for (unsigned int var = 0; var < this->toQmlwaitingTimePerProcess.size() ; ++var) {
        temp += toQmlwaitingTimePerProcess[var];
    }
    return  temp / this->numOfProcesses;
}
