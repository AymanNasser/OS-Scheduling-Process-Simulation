#include "process.h"

Process::Process(unsigned int a_processesNum, QString a_type)
{
    this->numOfProcesses = a_processesNum;
    this->algorithmType = a_type;
}
