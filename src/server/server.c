#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "../socket_wrappers/socket_wrappers.h"


void start_server(uint8_t host[4], uint16_t port){

    int connection, socket_fd;
    struct sockaddr_in addr;

    socket_fd = create_socket_fd();
    addr = binder(socket_fd, host, port);

    start_listen(socket_fd, 1);

    socklen_t addrlen = sizeof(addr);
    connection = accept(
        socket_fd,
        (struct sockaddr *)&addr,
        &addrlen
    );
    printf("connection: %d", connection);
}