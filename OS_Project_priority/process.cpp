#include "process.h"
#include <QDebug>

Process::Process(unsigned int a_processesNum, QString a_type)
{
    this->numOfProcesses = a_processesNum;
    this->algorithmType = a_type;
    //    for(unsigned int i = 0;i<numOfProcesses;i++)
    //    {
    //        processName.append("P"+QString(i));
    //    }
    //Just for Test Print The Arrival List to check the Behavior
    for(unsigned int i = 0;i<numOfProcesses;i++)
    {
        processName.append("P"+QString::number(i));
        // just for Test
        arrivalTime.append(rand()%20);
        burstTime.append(rand()%20);
        priority.append(rand()%20);
    }
    arrivalTime[0] = 2;
    arrivalTime[1] = 3;
    arrivalTime[2] = 10;
    arrivalTime[3] = 10;
    burstTime[0] = 5;
    burstTime[1] = 1;
    burstTime[2] = 2;
    burstTime[3] = 8;
    priority[0] = 1;
    priority[1] = 0;
    priority[2] = 3;
    priority[3] = 2;
    preemptive = false;
    //Just for Test Print The Arrival List to check the Behavior
    qDebug()<<"print Arrival List";
    for (unsigned int i=0; i < this->numOfProcesses; i++)
    {
        qDebug() << arrivalTime[i];
    }
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

unsigned int Process::sumBusttime()
{
    unsigned int Totalburstsum = 0;
    for(unsigned int i = 0 ; i < numOfProcesses ; i++)
    {
        Totalburstsum += burstTime[i];
    }
    return Totalburstsum;
}

void Process::handlePriority()
{
    // handling non-preemptive priority
    if(!preemptive)
    {
        unsigned int Totalgaintcharttime = sumBusttime();
        prioritySorting();
        unsigned int currentProcess = 0;
        unsigned int idleNumber = 0;
        for(unsigned int i = 0 ; i < Totalgaintcharttime; i++)
        {
            //  handling idle process
            if(arrivalTime[currentProcess] > i)
            {
                scheduledProcesses.insert("idle "+QString::number(idleNumber),arrivalTime[currentProcess] - i);
                Totalgaintcharttime += arrivalTime[currentProcess] - i;
                i += arrivalTime[currentProcess] - i - 1;
                idleNumber++;
            }
            // handling normal process
            else
            {
                scheduledProcesses.insert(processName[currentProcess],burstTime[currentProcess]);
                i += burstTime[currentProcess] - 1;
                currentProcess++;
            }
        }
        QList <QString> keys = scheduledProcesses.keys();
        for (int i=0; i < scheduledProcesses.size(); i++)
        {
            qDebug() << keys[i] << scheduledProcesses[keys[i]] ;
        }
    }
    else
    {
        unsigned int Totalburstsum = sumBusttime();
        prioritySorting();
        bool processINprogress = false;
        for(unsigned int i = 0 ; i < Totalburstsum ; i++)
        {
            if(i == arrivalTime[i])
            {
                processINprogress = true;
                for(unsigned j = 0; j < numOfProcesses ; j++)
                {
                    
                }
            }
        }
    }
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
