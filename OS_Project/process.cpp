#include "process.h"

Process::Process(unsigned int a_processesNum, QString a_type)
{
    this->numOfProcesses = a_processesNum;
    this->algorithmType = a_type;


    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        processName.append(QString("P" + QString(var)));
        index.append(var);
    }
    this->preemptive = 0;

    handleScheduling();
}

QString Process::getAlgorithmType()
{
    return  this->algorithmType;
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
        unsigned int overAllBurstTime = 0;
        for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
            overAllBurstTime+= burstTime[var];
        }
        QList <unsigned int > temp = burstTime;
        for (unsigned int i = 0; i < this->numOfProcesses -1 ; ++i) {
            for (unsigned int j = 0 ; j < this->numOfProcesses -1 - i; ++j) {
                if(burstTime[j] > burstTime[j+1])
                {
                    qSwap(burstTime[j],burstTime[j+1]);
                    qSwap(processName[j],processName[j+1]);
                    qSwap(index[j],index[j+1]);

                }
            }
        }
        unsigned int tick = 0 ,var;
        bool flag = false;
        for (; tick < overAllBurstTime; ) {
            for (var = 0; var < this->numOfProcesses ; ++var) {
                if(arrivalTime[index[var]] <= tick && burstTime[index[var]] !=0 )
                {
                   // qDebug() << "P" <<index[var] << arrivalTime[index[var]] <<  burstTime[index[var]] << '\n';
                    tick+= burstTime[index[var]] -1;
                    burstTime[index[var]] = 0;
                    flag = true;
                    this->scheduledProcesses.insert(QString("P"+ QString(index[var])),tick);
                    break;
                }
                else
                {
                    flag = false;
                }

            }
            if(!flag)
                tick++;
        }
        qDebug() << tick << '\n' ;
        for (unsigned int var = 0; var < numOfProcesses; ++var) {
           // qDebug() << index[var] << '\n' ;
        }

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
