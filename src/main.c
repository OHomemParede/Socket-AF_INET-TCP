#include <sys/socket.h>
#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

#include "../include/socket_wrappers.h"

#define PORT 1337

int main(){
    int listen_status, connection;
    int socket_file_descriptor;
    struct sockaddr_in addr;

    socket_file_descriptor = create_socket_fd();
    addr = do_a_bind(socket_file_descriptor, PORT);

    listen_status = listen(socket_file_descriptor, 3);
    printf("listen_status: %d", listen_status);

    socklen_t addrlen = sizeof(addr);
    connection = accept(
        socket_file_descriptor,
        (struct sockaddr *)&addr,
        &addrlen
    );
    printf("connection: %d", connection);

    return 0;
}
