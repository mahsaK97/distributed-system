

enum class NodeState
{
    Follower,
    Leader,
    Down


};

struct Node
{
    int id;
    char ip[16];
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
