#include "../../include/Protocol/MessageSerializer.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string serializeRequestVote(const RequestVote &request)
{
    json j;
    j["type"]= "request_vote";
    j["term"] =  request.term;
    j["candidate_id"] = request.candidateID;
    j["last_log_index"] = request.lastLogIndex;
    j["last_log_term"] = request.lastLogTerm;
    return j.dump();
}


RequestVote deserializeRequestVote(const std::string &text)
{
    json j = json::parse(text);

    RequestVote message;
    message.term = j.at("term").get<int>();
    message.candidateID = j.at("candidate_id").get<int>();
    message.lastLogIndex= j.at("last_log_index").get<int>();
    message.lastLogTerm = j.at("last_log_term").get<int>();

    return message;
}



std::string serializeRequestVoteReply(const RequestVoteReply &requestvotereply)
{
    json j;

    j["type"] = "request_vote_reply";
    j["term"] = requestvotereply.term;
    j["vote_granted"] = requestvotereply.voteGranted;

    return j.dump();
}

RequestVoteReply deserializeRequestVoteReply(const std::string &text)
{
    json j=json::parse(text);
    RequestVoteReply message;
    message.term = j.at("term").get<int>();
    message.voteGranted = j.at("vote_granted").get<bool>();

    return message;
}



std::string nodeStateToString(NodeState state)
{
    switch (state)
    {
          case NodeState::Candidate:
                 return "candidate";
          case NodeState::Follower:
                 return "follower";
          case NodeState::Leader:
                 return "leader";
          case NodeState::Down:
                 return "down";
    }

    return "unknown";

}





std::string makeClusterSnapshot(const std::vector<Node> &nodes,const std::string &event,int tick)
{
    json snapshot;
    snapshot["type"] = "cluster_update";
    snapshot["tick"] = tick;
    j["event"] = event;
    snapshot["nodes"]= json::array();

    int currentTerm=0;
    int leaderTerm =-1;

    json leaderID=nullptr;

    for(const NOde &node :nodes)
    {
        json nodeJson;

        nodeJson["id"]=node.getId();
        nodeJson["ip"]=node.getIp();
        nodeJson["port"]=node.getPort();
        nodeJson["state"] = nodeStateToString(node.getState);
        nodeJson["term"] = node.getTerm();

        snapshot["Nodes"].push_back(nodeJson);

        if(node.getTerm() > currentTerm)
        {
            currentTerm=node.getTerm();
        }
        if(node.getState()== NodeState::Leader &&
           node.getTerm() > leaderTerm)
        {
            leaderTerm = node.getTerm();
            leaderID = node.getId();
        }
    }

    snapshot["current_term"] = currentTerm;
    snapshot["leader_id"] = leaderID;

    return snapshot.dump(2);

}









