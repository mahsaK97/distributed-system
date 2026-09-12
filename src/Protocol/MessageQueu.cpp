#include "../../include/Protocol/MessageQueue.h"


MessageQueue::MessageQueue()
   :front(nullptr) , back(nullptr){};




MessageQueue::~MessageQueue()
{
    while(front != nullptr)
    {
        MessageNode *temp =front;
        front = front->next;
        delete temp;
    }


}

void MessageQueue::push(const MessageQueue &message)
{
    MessageNode *newNode = new MessageNode{message , nullptr};

    if(back == nullptr)
    {
        front = newNode;
        back = newNode;

    }

    else
    {
        back->next= newNode;
        back = newNode;
    }
}


bool MessageQueue::pop(Message &outMessage)
{
    if(front ==nullptr)
    {
        return false;
    }

    outMessage =fron->message;
    MessageNode *temp = fromt;
    front = front->next;

    if(front == nullptr)
    {
        back = nullptr;
    }
    delete temp;
    return true;
}


bool MessageQueue::IsEmpty() const
{
    return front = nullptr;
}








