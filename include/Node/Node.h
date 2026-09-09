#pragma once

#include <string>

enum class NodeState
{
    Follower,
    Leader,
    Condidate,
    Down


};

class Node
{
public:
    Node(int id, const std::string &ip, int port)

    void becameLeader();
    void becameFollower();
    void becameCandidate();


    NodeState getState() const {return state;}
    int getterm() const {return term;}


private:
    int id;
    int port;
    int term;

    std::string ip;

    NodeState state;

    int lastheartbeatTime;
    int electionTimeout;



};

