#include <arpa/inet.h>
#include <string>
#include <cstdint>
#include <sys/socket.h>


bool senAll(int socket_fd, const void *data, size_t length)
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



        if(sent <= 0)
        {
            return false;
        }
        totalsent+=sent;
    }
    return true;


    bool sendMessege(socket_fd , std::string &jsonpayload)
    {
        unit32_t messageLength = jsonpayload.size();
        unit32_t networkLength = hntol(messageLength);

        if (!sendAll(socket_fd, &networkLength, sizeof(networkLength)))
        {
            return false;
        }

        if(!senAll(socket_fd, jsonpayload.data(),jsonpayload.size()))
        {
            return false;
        }


        return true;

    }

}
