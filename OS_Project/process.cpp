#include "process.h"
#include <QtMath>

extern QList<qreal> BurstTime;
extern QList<unsigned int> ArrivalTime;
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
        processName.append("P"+QString::number(var+1));
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

void Process::SJF_swapListsNonPreemptive(){

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


void Process::SJF_swapLists(){

    for (unsigned int i = 0; i < this->numOfProcesses -1 ; ++i) {
        for (unsigned int j = 0 ; j < this->numOfProcesses -1 - i; ++j) {
            if(arrivalTime[j] > arrivalTime[j+1] || (arrivalTime[j] == arrivalTime[j+1] && burstTime[j] > burstTime[j+1]))
            {
                qSwap(arrivalTime[j],arrivalTime[j+1]);
                qSwap(burstTime[j],burstTime[j+1]);
                qSwap(processName[j],processName[j+1]);
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
    unsigned int ite;
    qreal tick = 0;
    bool unMatchedProcessPerTick = true;
    qreal overAllBurstTime = 0;

    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        overAllBurstTime+= burstTime[var];
    }


    /* Didn't support if the arrival time is more than the total processes burst time*/
    while(tick < overAllBurstTime){
        for (ite = 0; ite < this->numOfProcesses ; ++ite) {
            if(arrivalTime[ite] <= tick && burstTime[ite] !=0 )
            {
                toQmlScheduledId.append(QString("P" + QString::number(index[ite]+1)));
                toQmlwaitingTimePerProcess[index[ite]] = (tick - arrivalTime[ite]);
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
            toQmlScheduledId.append("idle");
            toQmlScheduledTime.append(tick);
        }
    }

}

void Process::RR_operation()
{
    QQueue<unsigned int> readyQueue;
    unsigned int lastCountedProcess = 0, min_idx, idealCounter = 0;
    qreal tick = 0, overAllBurstTime = 0;
    for (unsigned int i=0; i < this->numOfProcesses-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (unsigned int j=i+1; j < this->numOfProcesses; j++)
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

    QList <qreal> originalBurstTime = burstTime;

    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        overAllBurstTime+= burstTime[var];
    }

    while(tick < (overAllBurstTime + idealCounter)){

        for (int ite = tick; ite <= timeQuantum + tick; ++ite) {
            unsigned int itr = lastCountedProcess;
            while(itr < this->numOfProcesses)
            {
                if(arrivalTime[itr] <= ite)
                {
                    readyQueue.push_front(itr);
                    lastCountedProcess++;
                }
                itr++;
            }
            if(readyQueue.size() == 0) {
                toQmlScheduledId.append("idle");
                tick++;
                toQmlScheduledTime.append(tick);
                idealCounter++;
            }
        }
        if(readyQueue.size() != 0)
        {
            RR_queueProcessing(readyQueue,this->timeQuantum,tick,originalBurstTime);
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
        for (int var = 0; var < toQmlScheduledId.size(); ++var) {
        }
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
    }
    for(int i = 0; i < toQmlwaitingTimePerProcess.size();i++)
    {
        WaitingTimePerProcess.append(toQmlwaitingTimePerProcess[i]);
    }
}

void Process::handleFCFS()
{
    //1. Selection Sorting The List According To Arrival Time
    unsigned int i=0 , j=0 ,min_idx, idealCounter = 0;
    qreal overAllBurstTime = 0,tick = 0;
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

    while(tick < (overAllBurstTime + idealCounter )){
        for (unsigned int ite = 0; ite < this->numOfProcesses; ++ite) {
            if(arrivalTime[ite] <= tick && burstTime[ite] != 0)
            {
                toQmlwaitingTimePerProcess[ite] = tick - arrivalTime[ite];
                tick += burstTime[ite];
                burstTime[ite] = 0;
                toQmlScheduledId.append("P" + QString::number(index[ite]+1));
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
            toQmlScheduledId.append("idle");
            toQmlScheduledTime.append(tick);
            idealCounter++;
        }
    }

}

void Process::handleSJF()
{
    QList <qreal> temp_burstTime ;
    QList <unsigned int> temp_arrivalTime ;
    QMap<QString,qreal> process_burst;

    if(! (this->preemptive) )
    {
        SJF_swapListsNonPreemptive();
        SJF_nonPreemptiveOperation();
    }

    else
    {
        for(unsigned int i = 0 ; i < this->numOfProcesses ; i++)
        {
            temp_burstTime.append(burstTime[i]);
            temp_arrivalTime.append(arrivalTime[i]);
        }

        for(unsigned int j = 0; j < this->numOfProcesses ; j++)
        {
            process_burst[processName[j]] = burstTime[j];
        }

        SJF_swapLists();
        // handling preemptive sjf
        qreal Totalgaintcharttime = sumBursttime();
        unsigned int currentProcess = 0;
        unsigned int units = 0;
        unsigned int noOfProcess = numOfProcesses;
        QString processInexecution = "NULL";
        qreal i = 0;
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
                int processTakes = processTakeSJF(i + burstTime[currentProcess],i,currentProcess);
                if(noOfProcess > 0 && processTakes != -1)
                {
                    if(i < arrivalTime[arrivalTime.size()-1])
                    {
                        if(arrivalTime[processTakes] - i > 0)
                        {
                            toQmlScheduledTime.append(arrivalTime[processTakes]);
                            toQmlScheduledId.append(processName[currentProcess]);
                            burstTime[currentProcess] -= toQmlScheduledTime[units] - i;
                            i = arrivalTime[processTakes];
                            units++;
                        }
                        currentProcess = processTakes;
                        processInexecution = processName[currentProcess];
                    }
                    else
                    {
                        toQmlScheduledTime.append(burstTime[processTakes]+i);
                        toQmlScheduledId.append(processName[processTakes]);
                        i += burstTime[processTakes];
                        burstTime.removeAt(processTakes);
                        processName.removeAt(processTakes);
                        arrivalTime.removeAt(processTakes);
                        units++;
                        currentProcess = 0;
                        processInexecution = "NULL";
                        noOfProcess--;
                    }
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
                    currentProcess = 0;
                    processInexecution = "NULL";
                    noOfProcess--;
                }
            }
        }
    }
    QList<bool> process_arrived;
    for(int i = 0 ; i < temp_arrivalTime.size() ; i++)
    {
        process_arrived.append(false);
        QString process = "P" + QString::number(i+1);
        qreal processtime = temp_arrivalTime[i];
        for(int j = 0 ; j < toQmlScheduledTime.size();j++)
        {
            if(toQmlScheduledTime[j] > processtime && process == toQmlScheduledId[j] && process_burst[process] > 0)
            {
                process_arrived[i] = true;
                if(j != 0)
                    process_burst[process] -= toQmlScheduledTime[j] - toQmlScheduledTime[j-1];
                else
                    process_burst[process] -= toQmlScheduledTime[j];
            }
            else if (toQmlScheduledTime[j] > processtime && process != toQmlScheduledId[j] && process_burst[process] > 0)
            {
                if(process_arrived[i])
                {
                    if(j != 0)
                        toQmlwaitingTimePerProcess[i] += toQmlScheduledTime[j] - toQmlScheduledTime[j-1];
                    else
                        toQmlwaitingTimePerProcess[i] += toQmlScheduledTime[j];
                }
                else
                {
                    process_arrived[i] = true;
                    if(j != 0)
                        toQmlwaitingTimePerProcess[i] += toQmlScheduledTime[j] - temp_arrivalTime[i];
                    else
                        toQmlwaitingTimePerProcess[i] += toQmlScheduledTime[j];
                }
            }
        }
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

qreal Process::sumBursttime()
{
    qreal Totalburstsum = 0;
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

int Process::processTakeSJF(qreal time, qreal gnttchart, unsigned int currentProcess)
{
    int min_index = currentProcess;
    for(int i = currentProcess + 1; i < burstTime.size();i++)
    {
        if(gnttchart >= arrivalTime[arrivalTime.size() - 1])
        {
            if(burstTime[i] < burstTime[min_index])
            {
                min_index = i;
            }
        }
        else if(time > arrivalTime[i] && burstTime[i] < burstTime[min_index] - (arrivalTime[i] - gnttchart))
        {
            return i;
        }
    }
    return min_index == currentProcess ? -1 : min_index;
}

void Process::handlePriority()
{
    qreal Totalgaintcharttime = sumBursttime();
    unsigned int currentProcess = 0;
    unsigned int units = 0;

    QList <qreal> temp_burstTime ;
    QList <unsigned int> temp_arrivalTime ;
    for(unsigned int i = 0 ; i < this->numOfProcesses ; i++)
    {
        temp_burstTime.append(burstTime[i]);
        temp_arrivalTime.append(arrivalTime[i]);
    }
    QMap<QString,qreal> process_burst;
    for(unsigned int j = 0; j < this->numOfProcesses ; j++)
    {
        process_burst[processName[j]] = burstTime[j];
    }

    prioritySorting();

    // handling non-preemptive priority
    if(!preemptive)
    {
        qreal i = 0;
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
                burstTime.removeAt(currentProcess);
                processName.removeAt(currentProcess);
                arrivalTime.removeAt(currentProcess);
                priority.removeAt(currentProcess);
                units++;
                unsigned int min_priority = 0;
                for(int j = 0; j < priority.size() ; j++)
                {
                    if(priority[j] < priority[min_priority] && arrivalTime[j] <= i)
                    {
                        min_priority = j;
                    }
                }
                currentProcess = min_priority;
            }
        }
    }
    else
    {
        // handling preemptive priority
        unsigned int noOfProcess = numOfProcesses;
        QString processInexecution = "NULL";
        qreal i = 0;
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
                    qreal process_space = arrivalTime[processTakes] - i;
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
                    processInexecution = "NULL";
                    noOfProcess--;
                }
            }
        }
    }
    QList<bool> process_arrived;
    for(int i = 0 ; i < temp_arrivalTime.size() ; i++)
    {
        process_arrived.append(false);
        QString process = "P" + QString::number(i+1);
        qreal processtime = temp_arrivalTime[i];
        for(int j = 0 ; j < toQmlScheduledTime.size();j++)
        {
            if(toQmlScheduledTime[j] > processtime && process == toQmlScheduledId[j] && process_burst[process] > 0)
            {
                process_arrived[i] = true;
                if(j != 0)
                    process_burst[process] -= toQmlScheduledTime[j] - toQmlScheduledTime[j-1];
                else
                    process_burst[process] -= toQmlScheduledTime[j];
            }
            else if (toQmlScheduledTime[j] > processtime && process != toQmlScheduledId[j] && process_burst[process] > 0)
            {
                if(process_arrived[i])
                {
                    if(j != 0)
                        toQmlwaitingTimePerProcess[i] += toQmlScheduledTime[j] - toQmlScheduledTime[j-1];
                    else
                        toQmlwaitingTimePerProcess[i] += toQmlScheduledTime[j];
                }
                else
                {
                    process_arrived[i] = true;
                    toQmlwaitingTimePerProcess[i] += toQmlScheduledTime[j] - temp_arrivalTime[i];
                }
            }
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


void Process::RR_queueProcessing(QQueue <unsigned int> &a_readyQueue, unsigned int a_timeQuantum, qreal &a_tick,
                                 QList <qreal> &originalBurstTime ){

    if(a_timeQuantum <= 0 && a_readyQueue.empty() == true)
        return ;

    unsigned int tempIndex = a_readyQueue.back();

    if(burstTime[a_readyQueue.back()] > this->timeQuantum)
    {
        a_readyQueue.pop_back();
        a_tick += a_timeQuantum;
        toQmlScheduledId.append(QString("P" + QString::number(index[tempIndex]+1)));

        burstTime[tempIndex] -= a_timeQuantum;
        toQmlScheduledTime.append(a_tick);
        a_readyQueue.push_front(tempIndex);

        return ;
    }
    else {
        a_readyQueue.pop_back();
        a_tick += burstTime[tempIndex];
        toQmlScheduledId.append(QString("P" + QString::number(index[tempIndex]+1)));
        toQmlScheduledTime.append(a_tick);
        toQmlwaitingTimePerProcess[index[tempIndex]] = ((a_tick - arrivalTime[tempIndex])
                                                        - originalBurstTime[tempIndex]);
    }
}
