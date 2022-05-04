#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "../socket_wrappers/socket_wrappers.h"
#include "../utils/utils.h"


void start_server(uint8_t host[4], uint16_t port){

    int socket_fd, 
        bind_status,
        client_socket_fd,
        received_bytes;
    
    struct sockaddr_in addr;
    socklen_t addrlen;
    char buffer[1024]={'\x00'};

    socket_fd = create_socket_fd();

    addr = get_addr(host, 9001);
    addrlen = sizeof(addr);

    binder(socket_fd, addr);

    start_listen(socket_fd, 1);
    client_socket_fd = accept(
        socket_fd,
        (struct sockaddr *)&addr,
        &addrlen
    );

    
    while(1){
        recv(client_socket_fd, buffer, sizeof(buffer), 0);
        printf("> %s", buffer);
    }

}