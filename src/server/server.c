#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "./socket_wrappers/socket_wrappers.h"

#define PORT 1337

void start_server(){

int listen_status, connection, socket_fd;
    struct sockaddr_in addr;

    socket_fd = create_socket_fd();
    addr = binder(socket_fd, PORT);

    listen_status = listen(socket_fd, 3);

    // socklen_t addrlen = sizeof(addr);
    // connection = accept(
    //     socket_fd,
    //     (struct sockaddr *)&addr,
    //     &addrlen
    // );
    // printf("connection: %d", connection);
}