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


struct in_addr get_ipv4_addr(uint8_t *bytes){
    in_addr_t ipv4 = 0x00000000;
    struct in_addr address;
    
    for(int i=0; i<3; i++){
        ipv4 += bytes[i];
        ipv4 = ipv4 << 8;
    }
    ipv4 += bytes[3];

    // converting to big-endian notation.
    ipv4 = htonl(ipv4);

    address.s_addr = ipv4;

    return address;
}


struct sockaddr_in binder(int socket_fd, uint16_t port){
    struct sockaddr_in addr;
    int bind_status;
    uint8_t ipv4_address[4] = {127,0,0,1};

    // _____________________Procedimento de bind._____________________
    addr.sin_family = AF_INET;                   // int
    addr.sin_port = htons(port);                 // uint16_t
    addr.sin_addr = get_ipv4_addr(ipv4_address); // uint32_t


    bind_status = bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
    if (bind_status != 0) 
        raise_panic("socket bind failed");
    
    printf("Socket successfully binded. - bind_status: %d\n", bind_status);

    return addr;
}
