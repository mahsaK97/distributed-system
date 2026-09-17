#include <../../include/Node/Node.h>




std::mt19937 Node::rng(std::random_device{}());
Node::Node(int id, const std::string &ip, int port)
    :id(id) , ip(ip) , port(port) , state(NodeState::Follower) , term(0), lastheartbeatTime(0)
    {
        resetElectionTimeout()
    };




void Node::resetElectionTimeout()
{
    std::uniform_int_distribution<int>dist(5,10);
    electionTimeout =dist(rng);
}






void Node::becameCandidate()
{
    state = NodeState::Candidate;
    term= term++;
    resetElectionTimeout();
}


void Node::becameFollower(int newTerm)
{
    state = NodeState::Follower;
    term = newTerm;
    resetEleconTimeout();

}


void Node::becameLeader()
{
    state = NodeState::Leader;

}




