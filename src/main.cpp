#include "../include/Node/VirtualClock.h"
#include "../include/Node/Node.h"

#include <iostream>
#include <thread>
#include <chrono>



int main()
{
    VirtualClock Clock;
    Node node(1, "127.0.0.1" , 8000);
    bool running = true;


while(running)
{
    Clock.tick();

    if( node.getState() != NodeState::Leader
       &&Clock.now() - node.lastheartbeatTime >node.electionTimeout)
    {
        node.becameCandidate();
        std::cout <<"election time out! Node" <<node.getId()
        <<"is now a candidate" << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

}

return 0;



}
