#pragma once

#include "../../src/Protocol/MessageQueue.h"

struct MessageNode
{
    Message message;
    struct MessageNode *next;

};




class MessageQueue
{
public:
    MessageQueue();
    ~MessageQueue();


    void push(cons Messages &message);
    bool pop(Message &outMessage);
    bool IsEmpty() const;

};
