#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "../socket_wrappers/socket_wrappers.h"
#include "../utils/utils.h"

void start_client(uint8_t host[4], uint16_t port){
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
            fprintf(stdout, "\nSuccess connected.\n");
            break;
        }
        sleep(2); 

    }
    while(TRUE);
    

    char buffer[1024];
    uint16_t data_size;

    // send hi
    memset(buffer, '\x00', sizeof(buffer));
    buffer[0] = 'A';
    data_size = send(socket_fd, buffer, strlen(buffer), 0);
    fprintf(stdout, "[data_size: %d] > %s\n", data_size, buffer);


    // recv hi
    memset(buffer, '\x00', sizeof(buffer));
    data_size = recv(socket_fd, buffer, sizeof(buffer), 0);
    fprintf(stdout, "[data_size: %d] < %s\n", data_size, buffer);

    // send whatwever
    memset(buffer, '\x00', sizeof(buffer));
    fgets(buffer, sizeof(buffer), stdin);
    data_size = send(socket_fd, buffer, strlen(buffer), 0);
    fprintf(stdout, "[data_size: %d] > %s\n", data_size, buffer);

    close(socket_fd);
}