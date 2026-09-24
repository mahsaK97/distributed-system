#include <arpa/inet.h>
#include <string>
#include <cstdint>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>



#include "../../include/Network/TcpClient.h"


bool receiveAll(int socket_fd, void *data, size_t length)
{
    char *buffer = static_cast<char*>(data);
    size_t totalReceive =0;

    while(totalReceive < length)
    {
        ssize_t received = recv(
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


    if(messageLength > MAX_MESSAGE_SIZE)
    {
        return false;
    }

    messages.resize(messageLength);

    if(!receiveAll(socket_fd , messages.data() ,messageLength))
    {
        return false;
    }

    return true;

}

int TcpClient::connectTo(const std::string &ip , int port)
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0)
    {
        return -1;
    }


    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port =htons(port);

    if(inet_pton(AF_INET, ip.c_str(), &serverAddress.sin_addr) <= 0)
    {
        close(sock_fd);
        return -1;
    }

    if(connect(sock_fd, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
    {
        close(sock_fd);
        return -1;

    }

    return sock_fd;
}







