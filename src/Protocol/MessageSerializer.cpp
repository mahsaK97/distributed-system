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
    messages.term = j.at("term").get<int>();
    messages.candidateID = j.at("candidate_id").get<int>();
    messages.lastLogIndex= j.at("last_Log_index").get<int>();
    messages.lastLogTerm = j.at("last_Log_term").get<int>();

    return message;
}
