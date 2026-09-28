#include <iostream>
#include <vector>
#include "../include/Node/Node.h"
#include "../include/Node/VirtualClock.h"
#include "../include/Raft/RaftNode.h"

int main()
{

    std::vector<Node> nodes;
    nodes.emplace_back(1, "127.0.0.1", 9001);
    nodes.emplace_back(2, "127.0.0.1", 9002);
    nodes.emplace_back(3, "127.0.0.1", 9003);
    nodes.emplace_back(4, "127.0.0.1", 9004);


    auto buildPeerList = [&](int selfId)
    {
        std::vector<PeerInfo> peers;
        for (auto &n : nodes)
        {
            if (n.getId() != selfId)
            {
                peers.push_back({n.getId(), n.getIp(), n.getPort()});
            }
        }
        return peers;
    };

    std::vector<RaftNode> raftNodes;
    for (auto &n : nodes)
    {
        raftNodes.emplace_back(n, buildPeerList(n.getId()));
    }

    VirtualClock clock;


    auto broadcastRequestVote = [&](int candidateIndex)
    {
        RequestVote request;
        request.term = nodes[candidateIndex].getTerm();
        request.candidateID = nodes[candidateIndex].getId();

        for (size_t i = 0; i < nodes.size(); i++)
        {
            if (static_cast<int>(i) == candidateIndex)
                continue;

            RequestVoteReply reply = raftNodes[i].handleRequestVote(request);
            raftNodes[candidateIndex].handleRequestVoteReply(reply);
        }
    };


    std::cout << "--- Forcing a split vote between Node 1 and Node 2 ---" << std::endl;
    raftNodes[0].startElection(clock.now());
    raftNodes[1].startElection(clock.now());

    broadcastRequestVote(0);
    broadcastRequestVote(1);

    for (size_t i = 0; i < nodes.size(); i++)
    {
        std::cout << "Node " << nodes[i].getId()
                  << " term=" << nodes[i].getTerm()
                  << " won=" << raftNodes[i].hasWonElection() << std::endl;
    }


    std::cout << "\n--- Running main loop to resolve the split vote ---" << std::endl;
    bool electionResolved = false;
    int maxTicks = 50;

    while (!electionResolved && clock.now() < maxTicks)
    {
        clock.tick();

        for (size_t i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].getState() == NodeState::Leader)
                continue;

            if (clock.now() - nodes[i].getlastheartbeatTime() > nodes[i].getelectionTimeout())
            {
                raftNodes[i].startElection(clock.now());
                std::cout << "[tick " << clock.now() << "] Node " << nodes[i].getId()
                          << " timed out, starting election (term " << nodes[i].getTerm() << ")" << std::endl;

                broadcastRequestVote(static_cast<int>(i));

                if (nodes[i].getState() == NodeState::Leader)
                {

                    std::cout << "[tick " << clock.now() << "] Node " << nodes[i].getId()
                              << " WON the election! Now Leader (term " << nodes[i].getTerm() << ")" << std::endl;
                    electionResolved = true;
                }
            }
        }
    }

    return 0;
}
