#pragma once
#include <vector>
#include <variant>
#include "LogEntry.h"


struct RequestVote
{
    int term;
    int candidateID;

    int lastLogIndex;
    int lastLogTerm;

};

struct RequestVoteReply
{
    int term;
    bool voteGranted;

};

struct AppendEntries
{
    int term;
    int leaderID;


    int PrevLogIndex;
    int prevLogTerm;


    std::vector<LogEntry>entries;

    int leaderCommit;

};

struct AppendEntriesReply
{
    int term;
    bool success;

};

struct  MessageHeader
{
    int sender_id;
    int receiver_id;
    int message_type;
    int message_id;
    int term;
    int payload_size;

};


using MessagePayload = std::variant<
RequestVote,
RequestVoteReply,
AppendEntries,
AppendEntriesReply>;



struct Message
{
    MessageHeader Header;
    MessagePayload payload;

};

