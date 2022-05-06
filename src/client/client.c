#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "../socket_wrappers/socket_wrappers.h"
#include "../utils/utils.h"

int start_client(uint8_t host[4], uint16_t port){
    int socket_fd;
    struct sockaddr_in addr;
    int8_t connect_status;

    socket_fd = create_socket_fd();
    addr = get_addr(host, 9001);


    // ==================== Trying to connect to server (chat) ===================
    int try_count = 0;
    do{
        try_count++;
        fprintf(
            stdout, 
            "Connecting to %d.%d.%d.%d:%d ... [%d]\r",
            host[0], host[1], host[2], host[3],
            port,
            try_count
        );
        fflush(stdout);
        connect_status = connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
        if(connect_status == 0){
            fprintf(stdout, "\n%sSuccessfully connected.%s\n", global_colors.green, global_colors.end);
            break;
        }
        if(try_count == 3){
            close(socket_fd);
            raise_panic("Unable to connect to char server.");
        }
        sleep(2); 
    }
    while(TRUE);

    return socket_fd;
}