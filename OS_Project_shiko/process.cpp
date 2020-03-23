#include "process.h"

Process::Process(unsigned int a_processesNum, QString a_type)
{
    this->numOfProcesses = a_processesNum;
    this->algorithmType = a_type;
    for(unsigned int i = 0;i<numOfProcesses;i++)
    {
        processName.append("P"+QString(i));
        scheduledProcesses.insert(processName[i],arrivalTime[i]);
    }
}

void Process::prioritySorting()
{
    for(unsigned int i = 0; i < numOfProcesses - 1; i++)
    {
        for(unsigned int j = 0; j < numOfProcesses - i - 1; j++)
        {
            if((arrivalTime[i] > arrivalTime[j+1]) || (arrivalTime[i] == arrivalTime[j+1] && priority[i] > priority[j+1]))
            {
                qSwap(arrivalTime[i],arrivalTime[j+1]);
                qSwap(burstTime[i],burstTime[j+1]);
                qSwap(priority[i],priority[j+1]);
                qSwap(processName[i],processName[j+1]);
            }
        }
    }
}

void Process::handlePriority()
{
    if(!preemptive)
    {
        prioritySorting();
        for(unsigned int i = 0 ; i < numOfProcesses; i++)
        {
            scheduledProcesses[processName[i]] = burstTime[i];
        }
    }
    else
    {
        unsigned int Totalburstsum = 0;
        for(unsigned int i = 0 ; i < numOfProcesses ; i++)
        {
            Totalburstsum += burstTime[i];
        }
        prioritySorting();
        for(unsigned int i = 0 ; i < Totalburstsum ; i++)
        {

        }
    }
}
