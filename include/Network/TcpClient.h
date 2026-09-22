#pragma once

#include <string>

bool receiveAll(int socket_fd, void *data, size_t length);
bool receiveMessage(int socket_fd, std::string &messages);



class TcpClient
{
public:
    static int connectTo(const std::string &ip, int port);
};
