#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "../socket_wrappers/socket_wrappers.h"

void start_client(uint8_t host[4], uint16_t port){
    int socket_fd;
    struct sockaddr_in addr;

    socket_fd = create_socket_fd();
    addr = get_addr(host, 9001);

    connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr));

    char send_payload[1024]= {'\x00'};
    int sended_bytes = send(socket_fd, send_payload, sizeof(send_payload), 0);
    printf("[sended %d bytes]\n", sended_bytes);
}