#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "./socket_wrappers.h"
#include "../utils/utils.h"


int create_socket_fd(){
    int socket_fd;
    
    // _____________________Craindo um objeto socket TCP/IP._____________________
    socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd == -1){
        raise_panic("socket creation failed.");
    }

    return socket_fd;
}


struct in_addr get_ipv4_addr(uint8_t host[4]){
    in_addr_t ipv4 = 0x00000000;
    struct in_addr address;
    
    for(int i=0; i<3; i++){
        ipv4 += host[i];
        ipv4 = ipv4 << 8;
    }
    ipv4 += host[3];

    // converting to big-endian notation.
    ipv4 = htonl(ipv4);

    address.s_addr = ipv4;

    return address;
}

struct sockaddr_in get_addr(u_int8_t host[4], uint16_t port){
    struct sockaddr_in addr;

    // _____________________Procedimento de bind._____________________
    addr.sin_family = AF_INET;                   // int
    addr.sin_port = htons(port);                 // uint16_t
    addr.sin_addr = get_ipv4_addr(host);         // uint32_t

    return addr;
}


void binder(int socket_fd, struct sockaddr_in addr){
    int bind_status;

    bind_status = bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
    if (bind_status != 0) 
        raise_panic("socket bind failed");
    
    fprintf(stdout, "Socket successfully binded. - bind_status: %d\n", bind_status);
}


void start_listen(int socket_fd, int queue){
    int listen_status;
    listen_status = listen(socket_fd, queue);
    if(listen_status == -1)
        raise_panic("Failed to listen.");
}