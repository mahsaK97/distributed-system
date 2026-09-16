#pragma once

#include <string>
#include <random>

enum class NodeState
{
    Follower,
    Candidate,
    Leader,
    Down


};

class Node
{
public:
    Node(int id, const std::string &ip, int port);

    void becameLeader();
    void becameFollower(int newTerm);
    void becameCandidate(int newTerm);
    void resereletiontimeout();


    NodeState getState() const {return state;}
    int getterm() const {return term;}
    int getelectionTimeout() const {return electionTimeout;}
    int getlastheartbeatTime() const {return lastheartbeatTime;}
    int getid() const {return id;}
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

