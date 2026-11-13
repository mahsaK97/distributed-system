#pragma once
#include <string>
#include <vector>
#include "../Node/Node.h"
#include "Message.h"

std::string nodeStateToString(NodeState state);

std::string serializeRequestVote(const RequestVote &request);

RequestVote deserializeRequestVote(const std::string &text);

std::string serializeRequestVoteReply(const RequestVoteReply &requestvotereply);

RequestVoteReply deserializeRequestVoteReply(const std::string &text);

std::string makeClustrSnapeshot(const std::vector<Node> &nodes,
                                 const std::string &event,
                                 int tick);


