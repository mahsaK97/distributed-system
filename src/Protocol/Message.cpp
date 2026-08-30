#include <iostream>

typedef struct
{
    int sender_ID;
    int receiver_ID;
    int message_type;
    int message_ID;
    int term;
    int payload_size;

} MessageHeader;


typedef struct
{

    int data;


} MessagePayload;


typedef struct MessageNode
{
    Message message;
    struct MessageNode *next;

} MessageNode;
