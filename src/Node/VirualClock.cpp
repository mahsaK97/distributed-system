#include "../../include/Node/VirtualClock.h"



VirtualClock::VirtualClock()

    :currentTime(0);
{
}


void VirtualClock::tick()
{
    currentTime++;

}


int VirtualClock::now() const
{
    return currentTime;
}

void VirtualClock::reset()
{
    currentTime = 0;
}
