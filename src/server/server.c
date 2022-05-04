#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

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



    // ================= cht protocol =======
    char buffer[1024];
    uint16_t data_size;

    // recv hi
    memset(buffer, '\x00', sizeof(buffer));
    data_size = recv(client_socket_fd, buffer, sizeof(buffer), 0);
    fprintf(stdout, "[data_size: %d] < %s\n", data_size, buffer);

    // send hi
    memset(buffer, '\x00', sizeof(buffer));
    buffer[0] = 'B';
    data_size = send(client_socket_fd, buffer, strlen(buffer), 0);
    fprintf(stdout, "[data_size: %d] > %s\n", data_size, buffer);

    // recv whatever
    memset(buffer, '\x00', sizeof(buffer));
    data_size = recv(client_socket_fd, buffer, sizeof(buffer), 0);
    fprintf(stdout, "[data_size: %d] < %s\n", data_size, buffer);


    memset(buffer, '\x00', sizeof(buffer));
    data_size = recv(client_socket_fd, buffer, sizeof(buffer), 0);
    fprintf(stdout, "[data_size: %d] < %s\n", data_size, buffer);

    
    close(socket_fd);
}