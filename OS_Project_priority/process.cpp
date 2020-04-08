#include "process.h"
#include <QDebug>

Process::Process(unsigned int a_processesNum, QString a_type)
{
    this->numOfProcesses = a_processesNum;
    this->algorithmType = a_type;

    //Just for Test Print The Arrival List to check the Behavior
    for(unsigned int i = 0;i<numOfProcesses;i++)
    {
        processName.append("P"+QString::number(i));
        arrivalTime.append(rand()%20);
        burstTime.append(rand()%20);
        priority.append(rand()%20);
    }
    arrivalTime[0] = 3;
    arrivalTime[1] = 3;
    arrivalTime[2] = 4;
    arrivalTime[3] = 8;
    arrivalTime[4] = 9;
    arrivalTime[5] = 9;
    burstTime[0] = 3;
    burstTime[1] = 2;
    burstTime[2] = 2;
    burstTime[3] = 3;
    burstTime[4] = 2;
    burstTime[5] = 3;
    priority[0] = 4;
    priority[1] = 1;
    priority[2] = 0;
    priority[3] = 3;
    priority[4] = 5;
    priority[5] = 2;
    preemptive = true;
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

float Process::sumBusttime()
{
    float Totalburstsum = 0;
    for(unsigned int i = 0 ; i < numOfProcesses ; i++)
    {
        Totalburstsum += burstTime[i];
    }
    return Totalburstsum;
}

int Process::processTakePriority(float time, unsigned int currentProcess)
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
                time.append(arrivalTime[currentProcess]);
                process_name.append("idle");
                Totalgaintcharttime += arrivalTime[currentProcess] - i;
                i = arrivalTime[currentProcess];
                units++;
            }
            // handling normal process
            else
            {
                time.append(burstTime[currentProcess] + i);
                process_name.append(processName[currentProcess]);
                i += burstTime[currentProcess];
                currentProcess++;
                units++;
            }
        }
        for (unsigned int i=0; i < units; i++)
        {
            qDebug() << process_name[i] << time[i] ;
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
                time.append(arrivalTime[currentProcess]);
                process_name.append("idle");
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
                       time.append(process_space + i);
                       process_name.append(processName[currentProcess]);
                       burstTime[currentProcess] -= process_space;
                       i += process_space;
                       units++;
                   }
                   currentProcess = processTakes;
                   processInexecution = processName[currentProcess];
                }
                else
                {
                    time.append(burstTime[currentProcess] + i);
                    process_name.append(processName[currentProcess]);
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
            qDebug() << process_name[i] << time[i] ;
        }
    }
    //for(int i = 0 ; i < no)
}

void Process::handleFCFS()
{
    //1. Selection Sorting The List According To Arrival Time
    unsigned int i=0 , j=0 ,min_idx;
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
        qSwap(processName[i],processName[min_idx]);
    }

    //2. Fill the Map with the ("processName" as a key, "burst Time" as value)
    for (unsigned int i=0; i < this->numOfProcesses; i++)
    {
        scheduledProcesses.insert(processName[i],arrivalTime[i]);
    }

    qDebug()<<"print Arrival List";
    for (unsigned int i=0; i < numOfProcesses; i++)
    {
        qDebug() << processName[i] << " " << scheduledProcesses[processName[i]] ;
    }
}
