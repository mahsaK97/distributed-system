#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>
#include <cstdint>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <cerrno>



#include "../../include/Network/TcpServer.h"

bool sendAll(int socket_fd, const void *data, size_t length)
{
    const char *buffer= static_cast<const char*> (data);
    size_t totalsent = 0;

    while(totalsent < length)
    {
        ssize_t sent = send(
                            socket_fd,
                            buffer+totalsent,
                            length - totalsent,
                            0
                            );

        if(sent < 0)
        {
            if(errno == EINTR || errno == EAGAIN || errno == EWOULDBLOCK)
            {
                continue;
            }
            return false;
        }
        if(sent ==0)
        {
            return false;
        }


        totalsent+=static_cast<size_t>(sent);
    }
        return true;
}


bool sendMessage(int socket_fd , std::string &jsonpayload)
{
        uint32_t messageLength = jsonpayload.size();
        uint32_t networkLength = ht(messageLength);

        if (!sendAll(socket_fd, &networkLength, sizeof(networkLength)))
        {
            return false;
        }

        if(!sendAll(socket_fd, jsonpayload.data(),jsonpayload.size()))
        {
            return false;
        }


        return true;

}


TcpServer::TcpServer(int port):
    port(port), listen_fd(-1)
{

}

TcpServer::~TcpServer()
{
    stop();
}

bool TcpServer::start()
{
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd < 0)
    {
        std::cerr<< "FAILD TO CREATE SOCKET.\n" << std::endl;
        return false;
    }

    int opt =1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR,&OPT, sizeof(opt));
    sockaddr_in address {};
    address.sin_family =AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);


   if(bind(listen_fd,(sockaddr*)&address, sizeof(address)) < 0)
   {
       std::cerr << "BIND FAILD ON PORT." << std::endl;
       return false;

   }


   if(listen(listen_fd,10) < 0)
   {
       std::cerr << "LISTEN FAILD." <<std::endl;
       return false;

   }

   return true;

}


int TcpServer::acceptConnection()
{
    sockaddr_in clientAddress{};
    socklen_t addrLen = sizeof(clientAddress);

    int client_fd = accept(listen_fd, (sockaddr*)&clientAddress, &addrLen);
    return client_fd;
}


void TcpServer::stop()
{
    if(listen_fd >= 0)
    {
        close(listen_fd);
        listen_fd =-1;
    }
}
