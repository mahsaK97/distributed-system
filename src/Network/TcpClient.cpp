#include <arpa/inet.h>
#include <string>
#include <cstdint>
#include <sys/socket.h>


bool receiveAll(int socket_fd, void *data, size_t length)
{
    char *buffer = static_cast<char*>(data);
    size_t totalReceive =0;

    while(totalReceive < length)
    {
        size_t received = recv(
                               socket_fd,
                               buffer+totalReceive,
                               length-totalReceive,
                               0
                               );
        if(received <= 0)
        {
            return false;
        }

         totalReceive+=received;
    }

    return true;

    }


bool receiveMessage(int socket_fd, std::string &messages)
{
    uint32_t networkLength;

    if(!receiveAll(socket_fd, &networkLength, sizeof(networkLength)))
    {
        return false;
    }


    uint32_t messageLength = ntohl(networkLength);

    constexpr uint32_t MAX_MESSAGE_SIZE =1024 *1024;


    if(messagelength > MAX_MESSAGE_SIZE)
    {
        return false;
    }

    messages.resize(messagelength);

    if(!receiveAll(socket_fd , messages.data() ,messageslength))
    {
        return false;
    }

    return true;

}
