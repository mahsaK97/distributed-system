#pragma once

#include <vector>

#include "../Node/Node.h"
#include "../Protocol/Message.h"



struct PeerInfo
{
    int id;
    std::string ip;
    int port;

};


class RaftNode
{
public:
    RaftNode(Node &self, std::vector<PeerInfo> peers);

    void startElection();
    RequestVoteReply handleRequestVote(const RequestVote &Request);
    void handleRequestVoteReply(const RequestVoteReply &Reply);
    bool hasWonElection() const;

private:
    Node &self;
    std::vector<PeerInfo> peers;

    int votedfor;
    int votesReceived;
};
