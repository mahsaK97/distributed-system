#include <vector>
#include "../Protocol/LogEntry.h"


class RaftNode
{
private:
    std::vector <LogEntry> Log;


    int commiitIndex;
    int lastApplied;

};


