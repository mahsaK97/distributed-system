#include "../../include/Node.h"

Node::Node(int id, const std::string &ip, int port)
    : id(id) , ip(ip) , port(port) , state(NodeState::Follower) , term(6){}







void Node::becameCandidate()
{
    state = NodeState::Condidate;
    term++;
}


void Node::becameFollower()
{
    state = NodeState::Follower;
    term = newTerm;

}


void Node::becameLeader()
{
    state = NodeState::Leader;

}
