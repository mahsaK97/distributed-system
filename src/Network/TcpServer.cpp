#include <arpa/inet.h>
#include <string>
#include <sys/socket.h>



void sendMassege(int socket_fd, const std::string &jsonpayload)
{
    uint32_t messageLength  = jsonpayload.size();
    uint32_t networkLength =  htonl(messageLength);


    send(socket_fd , &networkLength , sizeof(networkLength), 0);
    send(socket_fd , jsonpayload.c_srt() ,jsonpayload.size(), 0);


}

