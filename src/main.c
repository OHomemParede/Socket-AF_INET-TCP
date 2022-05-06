#include <stdint.h>
#include <stdio.h>

#include "./server/server.h"
#include "./client/client.h"
#include "./utils/utils.h"
#include "./chat/chat.h"


int main(int argc, char **argv){
    uint32_t pid = getpid();

    printf("pid: %d\n", pid);
    uint8_t host[4] = {127, 0, 0, 1};

    if(!strncmp(argv[1], "server", 6)){
        
        start_server_result_t sockets_fd;
        sockets_fd = start_server(host, 9001);
        host_chat(sockets_fd);
    }

    if(!strncmp(argv[1], "client", 6)){
        int socket_fd;

        socket_fd = start_client(host, 9001);
        
        client_chat(socket_fd);
    }
    return 0;
}
