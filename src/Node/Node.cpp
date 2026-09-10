#include "../../include/Node.h"







std::mt19937 Node::rng(std::random_device{}())
Node::Node(int id, const std::string &ip, int port)
    : id(id) , ip(ip) , port(port) , state(NodeState::Follower) , term(6), lastheartbeatTime(0)
    {
        resetelectiiontimeout()
    }



void Node::resereletiontimeout()
{
    std::uniform_int_distribution<int>dist(5,10);
    electionTimeout =dist(rng);
}




void Node::becameCandidate()
{
    state = NodeState::Condidate;
    term++;
    resereletiontimeout();
}


void Node::becameFollower()
{
    state = NodeState::Follower;
    term = newTerm;
    resereletiontimeout();

}


void Node::becameLeader()
{
    state = NodeState::Leader;

}




