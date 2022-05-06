#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "./server/server.h"
#include "./client/client.h"
#include "./utils/utils.h"
#include "./chat/chat.h"


int main(int argc, char **argv){
    uint32_t pid = getpid();
    uint8_t host[4] = {127, 0, 0, 1};

    if(argc != 2){
        fprintf(
            stdout, 
            "%sUse this program as follow below: (server to start a chat, client to connect to one.)%s\n    %s%s [server | client]%s\n",
            global_colors.yellow,
            global_colors.end,
            global_colors.green,
            argv[0],
            global_colors.end
        );
        raise_panic("Missing arguments");
    }

    

    if(!strncmp(argv[1], "server", 6)){
        start_server_result_t sockets_fd;
    
        printf("PID: %d\n", pid);

        sockets_fd = start_server(host, 9001);
        host_chat(sockets_fd);
    }

    else if(!strncmp(argv[1], "client", 6)){
        int socket_fd;

        printf("PID: %d\n", pid);

        socket_fd = start_client(host, 9001);
        
        client_chat(socket_fd);
    }

    else {
        fprintf(
            stdout, 
            "%sUse this program as follow below: (server to start a chat, client to connect to one.)%s\n    %s%s [server | client]%s\n",
            global_colors.yellow,
            global_colors.end,
            global_colors.green,
            argv[0],
            global_colors.end
        );
        raise_panic("Wrong arguments");
    }
    return 0;
}
