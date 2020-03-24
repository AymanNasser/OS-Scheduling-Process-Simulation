#include "process.h"

Process::Process(unsigned int a_processesNum, QString a_type)
{
    this->numOfProcesses = a_processesNum;
    this->algorithmType = a_type;


    for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
        processName.append(QString("P" + QString(var)));
        index.append(var);
        waitingTimePerProcess.append(0);
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
        /* Calculating processes finishing time == > overAllBurstTime then
         * sorting the processes burst time in ascending order according to
         * SJF algorithm
        */
        unsigned int overAllBurstTime = 0;
        for (unsigned int var = 0; var < this->numOfProcesses ; ++var) {
            overAllBurstTime+= burstTime[var];
        }



        for (unsigned int i = 0; i < this->numOfProcesses -1 ; ++i) {
            for (unsigned int j = 0 ; j < this->numOfProcesses -1 - i; ++j) {
                if(burstTime[j] > burstTime[j+1])
                {
                    qSwap(arrivalTime[j],arrivalTime[j+1]);
                    qSwap(burstTime[j],burstTime[j+1]);
                    qSwap(processName[j],processName[j+1]);
                    qSwap(index[j],index[j+1]);

                }
            }
        }



        unsigned int tick = 0 ,var;
        bool unMatchedProcessPerTick = true;
        QList <unsigned int > temp;
        QList <QString> orderedProc;

        /* Didn't support if the arrival time is more than the total processes burst time*/
        while(tick < overAllBurstTime){
            for (var = 0; var < this->numOfProcesses ; ++var) {
                if(arrivalTime[var] <= tick && burstTime[var] !=0 )
                {
                    orderedProc.append(QString("P" + QString(index[var])));
                    qDebug() << processName[var] << arrivalTime[var] <<  burstTime[var] << '\n';
                    tick+= burstTime[var];
                    burstTime[var] = 0;
                    temp.append(tick-1);
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
                orderedProc.append("IDEAL");
                temp.append(tick);
                for (unsigned int var = 0; var < numOfProcesses; ++var) {
                    //waitingTimePerProcess[var]++;
                }
            }
        }




        qDebug() << tick -1  << '\n' ;
        for (unsigned int var = 0; var < temp.size(); ++var) {
           qDebug() << temp[var] << '\n' ;
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
