#include "../include/Node/VirtualClock.h"
#include "../include/Node/Node.h"

#include <iostream>



VirtualClock Clock;


while(running)
{
    Clock.tick();

    if( Node.getState() != NodeState::Leader
       &&Clock.now() - node.lastheartbeatTime >node.electionTimeout)
    {
        Node.becameCandidate();
        std::cout <<"election time out! Node" <<Node.id()
        <<"is now a candidate" << std::endl;
    }

}

