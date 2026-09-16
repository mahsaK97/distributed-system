#include <../../include/Node/Node.h>




std::mt19937 Node::rng(std::random_device{}());
Node::Node(int id, const std::string &ip, int port)
    :id(id) , ip(ip) , port(port) , state(NodeState::Follower) , term(0), lastheartbeatTime(0)
    {
        resetEletionTimeout()
    };




void Node::resetEletionTimeout()
{
    std::uniform_int_distribution<int>dist(5,10);
    electionTimeout =dist(rng);
}






void Node::becameCandidate(int newTerm)
{
    state = NodeState::Candidate;
    term= newTerm;
    resereletiontimeout();
}


void Node::becameFollower(int newTerm)
{
    state = NodeState::Follower;
    term = newTerm;
    resereletiontimeout();

}


void Node::becameLeader()
{
    state = NodeState::Leader;

}




