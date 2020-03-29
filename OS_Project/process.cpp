#include "process.h"




Process::Process(unsigned int a_processesNum, QString a_type)
{
    this->numOfProcesses = a_processesNum;
    this->algorithmType = a_type;


    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        index.append(var);
        toQmlwaitingTimePerProcess.append(0);
    }

    this->preemptive = 1;
    this->timeQuantum = 4;
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

void Process::SJF_preemptiveOperation()
{
    /* Calculating processes terminating time == > overAllBurstTime then
     * sorting the processes burst time in ascending order according to
     * SJF algorithm
    */
    unsigned int tick = 0 ,ite,minJobArrivedInQueue,nextJobCounter = 0;
    unsigned int overAllBurstTime = 0;

    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        overAllBurstTime+= burstTime[var];
    }
    minJobArrivedInQueue = burstTime[nextJobCounter] ;

    /* Didn't support if the arrival time is more than the total processes burst time
    *  problem in ideal case & incrementation of nextJobCounter when input is
    *  arrival time ==> {0,3,5,6,7}
    *  burst time ==> {4,1,1,3,2}
    */
    while(tick < overAllBurstTime){
        for (ite = 0; ite < this->numOfProcesses ; ++ite) {
            if(arrivalTime[ite] <= tick && burstTime[ite] != 0 && burstTime[ite] <= minJobArrivedInQueue)
            {
                toQmlScheduledId.append(QString("P" + QString(index[ite])));
                minJobArrivedInQueue = burstTime[nextJobCounter == this->numOfProcesses -1 ? nextJobCounter :++nextJobCounter] ;
                tick += burstTime[ite];
                toQmlScheduledTime.append(tick);

                burstTime[ite] = 0;
            }

            else if(arrivalTime[ite] <= tick && burstTime[ite] != 0)
            {
                burstTime[ite]--;
                toQmlScheduledId.append(QString("P" + QString(index[ite])));
                tick++;
                toQmlScheduledTime.append(tick);

            }
            else if(arrivalTime[ite] > tick && burstTime[ite] == 0 && burstTime[ite] > minJobArrivedInQueue)
            {
                tick++;
                toQmlScheduledId.append("IDEAL");
                toQmlScheduledTime.append(tick);
            }
        }
    }

}

void Process::RR_operation()
{
        unsigned int tick = 0, overAllBurstTime = 0 ;
    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        overAllBurstTime+= burstTime[var];
    }

    while(tick < overAllBurstTime){
        for (unsigned int ite = 0; ite < this->numOfProcesses ; ++ite) {
            if(arrivalTime[ite] <= tick && burstTime[ite] != 0 && burstTime[ite] >= this->timeQuantum)
            {
                tick += this->timeQuantum;
                toQmlScheduledId.append(QString("P" + QString(index[ite])));
                toQmlScheduledTime.append(tick);
                burstTime[ite] -= this->timeQuantum;


            }
            else if (arrivalTime[ite] <= tick && burstTime[ite] != 0 && burstTime[ite] < this->timeQuantum)
            {
                tick += burstTime[ite];
                toQmlScheduledId.append(QString("P" + QString(index[ite])));
                toQmlScheduledTime.append(tick);
                burstTime[ite] = 0;
            }
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
    else if(this->algorithmType == "RR")
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
        SJF_swapLists();
        SJF_preemptiveOperation();


//        for (int var = 0; var < numOfProcesses ;++var) {
//            qDebug() << index[var];
//        }

        for (int var = 0; var < toQmlScheduledId.size(); ++var) {
            qDebug() << toQmlScheduledId[var] << toQmlScheduledTime[var] ;
        }

    }
}

void Process::handleRoundRobin()
{
   RR_operation();

   for (int var = 0; var < toQmlScheduledId.size(); ++var) {
       qDebug() << toQmlScheduledId[var] << toQmlScheduledTime[var] ;
   }
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
