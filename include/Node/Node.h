#pragma once

#include <string>
#include <random>

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
    int getelectionTimeout() const {return electionTimeout;}
    int getlastheartbeatTime() const {return lastheartbeatTime;}
    void setlastheartbeatTime(int time) {lastheartbeatTime = time;}


private:
    int id;
    int port;
    int term;

    std::string ip;

    NodeState state;

    int lastheartbeatTime;
    int electionTimeout;

    static std::mt19937 rng;



};

