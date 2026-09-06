#include <arpa/inet.h>
#include <string>
#include <sys/socket>


std::string receiveMessage(int socket_fd)
{
    uint32_t networkLength;
    recv(socket_fd, &networkLength, sizeof(socket_fd), MSG_WAITALL);

    uint32_t messageLength = ntohl(networkLength);


    std::string buffer(messageLength , '\0');
    recv(socket_fd , &buffer[0], messageLength , MSG_WAITALL);


    return n8

}
