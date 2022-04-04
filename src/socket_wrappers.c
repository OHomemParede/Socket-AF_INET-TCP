#include <sys/socket.h>
#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

#include "../include/socket_wrappers.h"


struct in_addr ipv4_addr(uint8_t oct1, uint8_t oct2, uint8_t oct3, uint8_t oct4){
    in_addr_t sum = 0;
    struct in_addr address;
    
    sum += oct1;
    sum = sum << 8;

    sum += oct2;
    sum = sum << 8;

    sum += oct3;
    sum = sum << 8;

    sum += oct4;

    address.s_addr = sum;

    return address;
}



int create_socket_fd(){
    int socket_file_descriptor;
    
    /**
     * _____________________Craindo um objeto socket TCP/IP._____________________
     * 
     * AF_INET          IPv4 Internet protocols.
     * SOCK_STREAM      Reliable, two-way, connection-based, sequenced, byte-streams.
     * IPPROTO_TCP      Transmission Control Protocol.
     * 
     * domain      Specifies  the communications domain in which a
     *             socket is to be created.
     * 
     * type        Specifies the type of socket to be created.
     * 
     * protocol    Specifies a particular protocol to be used with
     *             the  socket.  Specifying a protocol of 0 causes
     *             socket() to use an unspecified default protocol
     *             appropriate for the requested socket type.
     */
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_file_descriptor == -1){
        printf("socket creation failed... - socket_file_descriptor value: %d\n", socket_file_descriptor);
        exit(EXIT_FAILURE);
    }
    printf("Socket successfully created... - socket_file_descriptor value: %d\n", socket_file_descriptor);

    return socket_file_descriptor;
}




struct sockaddr_in do_a_bind(int socket_file_descriptor, uint16_t port){
    struct sockaddr_in addr;
    int bind_status;

    // _____________________Procedimento de bind._____________________
    addr.sin_family = AF_INET; // int
    addr.sin_port = port; // uint16_t
    addr.sin_addr = ipv4_addr(0, 0, 0, 0); // uint32_t

    // Algumas vezes ao encerrar o servidor, é possível que fique resquícios de sua existencia no kernel,
    // impossibilitando o uso do endereço e porta que o socket tinha dado bind. Se esse for o caso, tenta 
    // reutilizá-los
    int boolean = 1; // opção booleana (sim, no caso)
    if(setsockopt(socket_file_descriptor, SOL_SOCKET, SO_REUSEADDR, &boolean, sizeof(boolean)) == -1) { 
      perror("new_tcp_server: setsockopt");
      exit(EXIT_FAILURE);
    }

    bind_status = bind(socket_file_descriptor, (struct sockaddr *)&addr, sizeof(addr));
    if (bind_status != 0) {
        printf("socket bind failed... - bind_status: %d\n", bind_status);
        exit(EXIT_FAILURE);
    }
    printf("Socket successfully binded... - bind_status: %d\n", bind_status);

    return addr;
}

