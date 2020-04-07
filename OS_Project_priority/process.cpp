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
    arrivalTime[0] = 0;
    arrivalTime[1] = 0;
    arrivalTime[2] = 4;
    arrivalTime[3] = 12;
    //arrivalTime[4] = 0;
    burstTime[0] = 5;
    burstTime[1] = 10;
    burstTime[2] = 3;
    burstTime[3] = 7;
    //burstTime[4] = 5;
    priority[0] = 1;
    priority[1] = 2;
    priority[2] = 0;
    priority[3] = 3;
    //priority[4] = 2;
    preemptive = true;
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

int Process::processTakePriority(unsigned int index, unsigned int currentProcess)
{
    for(int i = currentProcess + 1; i < arrivalTime.size();i++)
    {
        if(index == arrivalTime[i] && priority[currentProcess] > priority[i])
        {
            return i;
        }
    }
    return -1;
}

void Process::handlePriority()
{
    unsigned int Totalgaintcharttime = sumBusttime();
    prioritySorting();
    unsigned int currentProcess = 0;
    unsigned int idleNumber = 0;
    unsigned int units = 0;
    // handling non-preemptive priority
    if(!preemptive)
    {
        for(unsigned int i = 0 ; i < Totalgaintcharttime; i++)
        {
            //  handling idle process
            if(arrivalTime[currentProcess] > i)
            {
                scheduledProcesses.insert("idle "+QString::number(idleNumber),arrivalTime[currentProcess] - i);
                time.append(arrivalTime[currentProcess] - i);
                process_name.append("idle "+QString::number(idleNumber));
                Totalgaintcharttime += arrivalTime[currentProcess] - i;
                i += arrivalTime[currentProcess] - i - 1;
                idleNumber++;
                units++;
            }
            // handling normal process
            else
            {
                scheduledProcesses.insert(processName[currentProcess],burstTime[currentProcess]);
                time.append(burstTime[currentProcess]);
                process_name.append(processName[currentProcess]);
                i += burstTime[currentProcess] - 1;
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
        int waitingProcess = -1;
        QString processInexecution = "NULL";
        for(unsigned int i = 0 ; i < Totalgaintcharttime; i++)
        {
            //  handling idle process
            if(arrivalTime[currentProcess] > i && processInexecution == "NULL")
            {
                time.append(arrivalTime[currentProcess] - i);
                process_name.append("idle "+QString::number(idleNumber));
                Totalgaintcharttime += arrivalTime[currentProcess] - i;
                i += arrivalTime[currentProcess] - i - 1;
                idleNumber++;
                units++;
            }
            // handling normal process
            else
            {
                // check if it in first time in the schedual
                if(processInexecution == "NULL")
                {
                    if(noOfProcess > 1 && i == arrivalTime[currentProcess + 1] && arrivalTime[currentProcess + 1] != arrivalTime[currentProcess])
                    {
                        currentProcess++;
                        time.append(1);
                        process_name.append(processName[currentProcess]);
                        burstTime[currentProcess]--;
                        processInexecution = processName[currentProcess];
                        units++;
                    }
                    else
                    {
                        time.append(1);
                        process_name.append(processName[currentProcess]);
                        burstTime[currentProcess]--;
                        processInexecution = processName[currentProcess];
                        units++;
                        if(burstTime[currentProcess] == 0)
                        {
                            burstTime.removeAt(currentProcess);
                            processName.removeAt(currentProcess);
                            arrivalTime.removeAt(currentProcess);
                            processInexecution = "NULL";
                            currentProcess = 0;
                            noOfProcess--;
                            continue;
                        }
                    }
                }
                else
                {
                    if(noOfProcess > 1 && processTakePriority(i,currentProcess) != -1)//arrivalTime[currentProcess + 1] && priority[currentProcess] > priority[currentProcess + 1])
                    {
                        waitingProcess = currentProcess;
                        currentProcess = processTakePriority(i,currentProcess);
                        time.append(1);
                        process_name.append(processName[currentProcess]);
                        burstTime[currentProcess]--;
                        processInexecution = processName[currentProcess];
                        units++;
                        if(burstTime[currentProcess] == 0)
                        {
                            burstTime.removeAt(currentProcess);
                            processName.removeAt(currentProcess);
                            arrivalTime.removeAt(currentProcess);
                            currentProcess = waitingProcess;
                            processInexecution = "NULL";
                            waitingProcess = -1;
                            noOfProcess--;
                        }
                    }
                    else
                    {
                        processInexecution = processName[currentProcess];
                        time[units - 1]++;
                        burstTime[currentProcess]--;
                        if(burstTime[currentProcess] == 0)
                        {
                            burstTime.removeAt(currentProcess);
                            processName.removeAt(currentProcess);
                            arrivalTime.removeAt(currentProcess);
                            processInexecution = "NULL";
                            currentProcess = 0;
                            noOfProcess--;
                            continue;
                        }
                    }
                }
            }
        }
        for (unsigned int i=0; i < units; i++)
        {
            qDebug() << process_name[i] << time[i] ;
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
