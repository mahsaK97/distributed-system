#include <arpa/inet.h>
#include <string>
#include <cstdint>
#include <sys/socket.h>
#include <cerrno>

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
        uint32_t networkLength = htonl(messageLength);

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

