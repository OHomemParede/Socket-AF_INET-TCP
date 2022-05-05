#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "../socket_wrappers/socket_wrappers.h"
#include "../utils/utils.h"
#include "./server.h"

start_server_result_t start_server(uint8_t host[4], uint16_t port){

    start_server_result_t result;
    int socket_fd, client_socket_fd;
    
    struct sockaddr_in addr;
    socklen_t addrlen;

    socket_fd = create_socket_fd();

    addr = get_addr(host, 9001);
    addrlen = sizeof(addr);

    binder(socket_fd, addr);

    start_listen(socket_fd, 1);
    
    printf("> %d\n", client_socket_fd);
    close(client_socket_fd);
    close(socket_fd);

    result.socket_fd = socket_fd;
    result.client_socket_fd = client_socket_fd;
    return result;

}