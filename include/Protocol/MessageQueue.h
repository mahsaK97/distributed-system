#pragma once

#include "../Message.h"

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


    void push(const Messages &message);
    bool pop(Message &outMessage);
    bool IsEmpty()const;

private:
    MessageNode *front;
    MessageNode *back;

};
