#pragma once

#include <string>
#include <cstdint>


bool sendAll(int socket_fd, const void *data, size_t length);
bool sendMessage(int socket_fd, std::string &jsonpayload);


class TcpServer
{
public:
    TcpServer(int port);
    ~TcpServer();


    bool start();
    int acceptConnection();
    void stop();


private:
    int port;
    int listen_fd;
};
