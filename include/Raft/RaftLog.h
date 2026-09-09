#pragma once

#include <vector>
#include "../Protocol/LogEntry.h"


class RaftLog
{
private:
    std::vector <LogEntry> Log;


    int commitIndex;
    int lastapplied;

};


