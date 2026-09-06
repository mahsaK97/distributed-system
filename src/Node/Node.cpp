#include <iostream>

enum class NodeState
{
    Follower,
    Leader,
    Down


};

struct Node
{
    int ID;
    char IP[16];
    int port;
    NodeState state;
    int term;


};


enum class MessageType
{

     RequestVote,
     RequestVoteReply,
     AppendEntries,
     AppendEntriesReply

};
