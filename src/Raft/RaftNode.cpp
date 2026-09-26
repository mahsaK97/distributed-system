#include "../../include/Raft/RaftNode.h"

RaftNode::RaftNode(Node &self, std::vector<PeerInfo> peers)
   :self(self), peers(peers) , votedfor(-1), votesReceived(0)
   {

   }



void RaftNode::startElection()
{
    self.becameCandidate();
    votedfor = self.getId();
    votesReceived =1;
}


RequestVoteReply RaftNode::handleRequestVote(const RequestVote &request)
{
    RequestVoteReply reply;
    reply.term=self.getTerm();

    if(request.term < self.getTerm())
    {
        reply.voteGranted=false;
        return reply;
    }


    if(request.term > self.getTerm())
    {
        self.becameFollower(request.term);
        votedfor =-1;
    }

    if(votedfor == -1 || votedfor == request.candidateID)
    {
        votedfor = request.candidateID;
        reply.term = self.getTerm();
        reply.voteGranted =true;
        return reply;
    }

    reply.voteGranted = false;
    return reply;
}

void RaftNode::handleRequestVoteReply(const RequestVoteReply &reply)
{
    if(self.getState() != NodeState::Condidate)
    {
        return;
    }

    if(reply.term > self.getTerm())
    {
        self.becameFollower(reply.term);
        return;
    }

    if(reply.voteGranted)
    {
        votesReceived++;
    }
}


bool RaftNode::handleWonElection() const
{
    int totalNodes=static_cast<int>(peers.size()) +1;
    int majority =totalNodes /2 +1;
    return votesReceived >= majority;

}
