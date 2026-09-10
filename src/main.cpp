#include "../include/Node/VirtualClock.h"
#include "../include/Node/Node.h"




VirtualClock Clock;


while(runnig)
{
    Clock.tick();

    if( Node.getState() != NodeState::Leader
       &&Clock.now() - node.lastheaetbeatTime >node.electionTimeout)
    {
        Node.becameCandidate();
        std::cout <<"election time out! Node" <<Node.id()
        <<"is now a candidate" << std::endl;
    }

}

