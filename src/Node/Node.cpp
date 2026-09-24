#include "../../include/Node/Node.h"




std::mt19937 Node::rng(std::random_device{}());
Node::Node(int id, const std::string &ip, int port)
    :id(id) ,port(port)  , term(0) , ip(ip), state(NodeState::Follower) , lastheartbeatTime(0)
    {
        resetElectionTimeout();
    }




void Node::resetElectionTimeout()
{
    std::uniform_int_distribution <int> dist(5,10);
    electionTimeout =dist(rng);
}






void Node::becameCandidate()
{
    state = NodeState::Candidate;
    term++;
    resetElectionTimeout();
}


void Node::becameFollower(int newTerm)
{
    state = NodeState::Follower;
    term = newTerm;
    resetElectionTimeout();


}


void Node::becameLeader()
{
    state = NodeState::Leader;

}




