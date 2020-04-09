#include "process.h"
#include <QDebug>

extern QList<qreal> BurstTime;
extern QList<qreal> ArrivalTime;
extern QList<unsigned int> Priority;
extern QList <QString> ScheduledId;
extern QList <qreal> ScheduledTime;
extern QList <qreal> WaitingTimePerProcess;
extern QString ProcessType;
extern bool isPreemptive;
extern int NUmberOfProcess;
extern int TimeQuantum;

Process::Process()
{
    this->numOfProcesses = NUmberOfProcess;
    this->algorithmType = ProcessType;
    this->preemptive = isPreemptive;
    this->timeQuantum = TimeQuantum;
    for (unsigned int var = 0; var < this->numOfProcesses ; var++)
    {
        processName.append("P"+QString::number(var));
        toQmlwaitingTimePerProcess.append(0);
        index.append(var);
        burstTime.append(BurstTime[var]);
        arrivalTime.append(ArrivalTime[var]);
    }
    if(algorithmType == "Priority")
    {
        for (unsigned int var = 0; var < this->numOfProcesses ; var++)
        {
            priority.append(Priority[var]);
        }
    }
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
            toQmlScheduledId.append("ideal");
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
    unsigned int tick = 0 ,ite,minJobArrivedInQueue,unMatchedProccessPerTick = 0;
    unsigned int overAllBurstTime = 0;

    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        overAllBurstTime+= burstTime[var];
    }
    minJobArrivedInQueue = burstTime[0] ;

    /* Didn't support if the arrival time is more than the total processes burst time */
    while(tick < overAllBurstTime){
        for (ite = 0; ite < this->burstTime.size() ; ++ite) {
            if(arrivalTime[ite] <= tick && burstTime[ite] != 0 && burstTime[ite] <= minJobArrivedInQueue)
            {
                toQmlScheduledId.append(QString("P" + QString(index[ite])));

                tick += burstTime[ite];
                toQmlScheduledTime.append(tick);
                toQmlwaitingTimePerProcess.append(tick - arrivalTime[ite]);
                burstTime.removeAt(ite);
                arrivalTime.removeAt(ite);
                index.removeAt(ite);

                if(burstTime.size() != 0)
                    minJobArrivedInQueue = burstTime[0];
                break;
            }

            else if(arrivalTime[ite] <= tick && burstTime[ite] != 0)
            {
                burstTime[ite]--;
                toQmlScheduledId.append(QString("P" + QString(index[ite])));
                tick++;
                toQmlScheduledTime.append(tick);
                toQmlwaitingTimePerProcess.append(tick - arrivalTime[ite]);

                if(burstTime[ite] == 0)
                {
                    arrivalTime.removeAt(ite);
                    burstTime.removeAt(ite);
                    index.removeAt(ite);
                }
            }
        }
        if(unMatchedProccessPerTick == toQmlScheduledId.size())
        {
            tick++;
            toQmlScheduledId.append("ideal");
            toQmlScheduledTime.append(tick);
        }
        else
        {
            unMatchedProccessPerTick = toQmlScheduledId.size();
        }
    }

}

void Process::RR_operation()
{
    unsigned int tick = 0, overAllBurstTime = 0 ;
    bool unMatchedProcessPerTick = false;
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
                unMatchedProcessPerTick = false;
            }
            else if (arrivalTime[ite] <= tick && burstTime[ite] != 0 && burstTime[ite] < this->timeQuantum)
            {
                tick += burstTime[ite];
                toQmlScheduledId.append(QString("P" + QString(index[ite])));
                toQmlScheduledTime.append(tick);
                burstTime[ite] = 0;
                unMatchedProcessPerTick = false;
            }
            else {
                unMatchedProcessPerTick = true;
            }
        }
        if(unMatchedProcessPerTick)
        {
            tick++;
            toQmlScheduledId.append("ideal");
            toQmlScheduledTime.append(tick);
        }

    }




}




QString Process::getAlgorithmType()
{
    return  this->algorithmType;
}

QList<qreal> Process::getScheduledProcessBurstTime()
{
    return this->toQmlScheduledTime;
}

QList<qreal> Process::getSchduledProcessWaitingTime()
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
    else if(this->algorithmType == "Round Robin")
    {
        handleRoundRobin();

    }
    else if(this->algorithmType == "Priority")
    {
        handlePriority();
    }
    ScheduledId.clear();
    ScheduledTime.clear();
    WaitingTimePerProcess.clear();
    for(int i = 0; i < toQmlScheduledId.size();i++)
    {
        ScheduledId.append(toQmlScheduledId[i]);
        ScheduledTime.append((toQmlScheduledTime[i]));
        //WaitingTimePerProcess.append(toQmlwaitingTimePerProcess[i]);
    }
}

void Process::handleFCFS()
{
    //1. Selection Sorting The List According To Arrival Time
    unsigned int i=0 , j=0 ,min_idx, overAllBurstTime = 0,tick = 0;
    bool unMatchedProcessPerTick = false;
    for (i=0; i < this->numOfProcesses-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j=i+1; j < this->numOfProcesses; j++)
        {
            if(arrivalTime[j]<arrivalTime[min_idx])
            {
                // update The Minmum index
                min_idx = j;
            }
        }
        // Making The Swap for 3 lists ("ArrivalTime,burstTime.)
        qSwap(arrivalTime[i],arrivalTime[min_idx]);
        qSwap(burstTime[i],burstTime[min_idx]);
        qSwap(index[i],index[min_idx]);
    }

    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        overAllBurstTime+= burstTime[var];
    }

    while(tick < overAllBurstTime){
        for (unsigned int ite = 0; ite < this->numOfProcesses; ++ite) {
            if(arrivalTime[ite] <= tick && burstTime[ite] != 0)
            {
                toQmlwaitingTimePerProcess[ite] = tick - arrivalTime[ite];
                tick += burstTime[ite];
                burstTime[ite] = 0;
                toQmlScheduledId.append("P" + QString(index[ite]));
                toQmlScheduledTime.append(tick);

                unMatchedProcessPerTick = false;

            }
            else
            {
                unMatchedProcessPerTick = true;
            }
        }
        if(unMatchedProcessPerTick)
        {
            tick++;
            toQmlScheduledId.append("ideal");
            toQmlScheduledTime.append(tick);
        }
    }

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


    }
}

void Process::handleRoundRobin()
{
   RR_operation();

}

void Process::prioritySorting()
{
    for(unsigned int i = 0; i < numOfProcesses - 1; i++)
    {
        for(unsigned int j = 0; j < numOfProcesses - i - 1; j++)
        {
            if((arrivalTime[j] > arrivalTime[j+1]) || (arrivalTime[j] == arrivalTime[j+1] && priority[j] > priority[j+1]))
            {
                qSwap(arrivalTime[j],arrivalTime[j+1]);
                qSwap(burstTime[j],burstTime[j+1]);
                qSwap(priority[j],priority[j+1]);
                qSwap(processName[j],processName[j+1]);
            }
        }
    }
}

qreal Process::sumBusttime()
{
    float Totalburstsum = 0;
    for(unsigned int i = 0 ; i < numOfProcesses ; i++)
    {
        Totalburstsum += burstTime[i];
    }
    return Totalburstsum;
}

int Process::processTakePriority(qreal time, unsigned int currentProcess)
{
    for(int i = currentProcess + 1; i < arrivalTime.size();i++)
    {
        if(time >= arrivalTime[i] && priority[currentProcess] > priority[i])
        {
            return i;
        }
    }
    return -1;
}

void Process::handlePriority()
{
    float Totalgaintcharttime = sumBusttime();
    prioritySorting();
    unsigned int currentProcess = 0;
    unsigned int units = 0;
    // handling non-preemptive priority
    if(!preemptive)
    {
        float i = 0;
        while(i < Totalgaintcharttime)
        {
            //  handling idle process
            if(arrivalTime[currentProcess] > i)
            {
                toQmlScheduledTime.append(arrivalTime[currentProcess]);
                toQmlScheduledId.append("idle");
                Totalgaintcharttime += arrivalTime[currentProcess] - i;
                i = arrivalTime[currentProcess];
                units++;
            }
            // handling normal process
            else
            {
                toQmlScheduledTime.append(burstTime[currentProcess] + i);
                toQmlScheduledId.append(processName[currentProcess]);
                i += burstTime[currentProcess];
                currentProcess++;
                units++;
            }
        }
        for (unsigned int i=0; i < units; i++)
        {
            qDebug() << toQmlScheduledId[i] << toQmlScheduledTime[i] ;
        }
    }
    else
    {
        // handling preemptive priority
        unsigned int noOfProcess = numOfProcesses;
        QString processInexecution = "NULL";
        float i = 0;
        while(i < Totalgaintcharttime)
        {
            //  handling idle process
            if(arrivalTime[currentProcess] > i && processInexecution == "NULL")
            {
                toQmlScheduledTime.append(arrivalTime[currentProcess]);
                toQmlScheduledId.append("idle");
                Totalgaintcharttime += arrivalTime[currentProcess] - i;
                i = arrivalTime[currentProcess];
                units++;
            }
            // handling normal process
            else
            {
                int processTakes = processTakePriority(i + burstTime[currentProcess],currentProcess);
                if(noOfProcess > 0 && processTakes != -1)
                {
                   float process_space = arrivalTime[processTakes] - i;
                   if(process_space > 0)
                   {
                       toQmlScheduledTime.append(process_space + i);
                       toQmlScheduledId.append(processName[currentProcess]);
                       burstTime[currentProcess] -= process_space;
                       i += process_space;
                       units++;
                   }
                   currentProcess = processTakes;
                   processInexecution = processName[currentProcess];
                }
                else
                {
                    toQmlScheduledTime.append(burstTime[currentProcess] + i);
                    toQmlScheduledId.append(processName[currentProcess]);
                    i += burstTime[currentProcess];
                    units++;
                    burstTime.removeAt(currentProcess);
                    processName.removeAt(currentProcess);
                    arrivalTime.removeAt(currentProcess);
                    priority.removeAt(currentProcess);
                    currentProcess = 0;
                    processInexecution = "NUll";
                    noOfProcess--;
                }
            }
        }
        for (unsigned int i=0; i < units; i++)
        {
            qDebug() << toQmlScheduledId[i] << toQmlScheduledTime[i] ;
        }
    }
}

qreal Process::calcOverAllAverageWaitingTime()
{
    qreal temp = 0;
    for (unsigned int var = 0; var < this->toQmlwaitingTimePerProcess.size() ; ++var) {
        temp += toQmlwaitingTimePerProcess[var];
    }
    return  temp / this->numOfProcesses;
}
