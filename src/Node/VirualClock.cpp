#include "../../include/Node/VirtualClock.h"
#include


VirtualClock::VirtualClock()

    :currentTime();
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
