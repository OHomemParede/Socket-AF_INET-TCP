#include <sys/socket.h>
#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

#ifndef __USE_XOPEN2K
#define __USE_XOPEN2K
#endif
#include <netdb.h> // see line 563

#include "./socket_wrappers.h"
#include "../utils/utils.h"


struct in_addr ipv4_addr(uint8_t *bytes){
    in_addr_t ipv4 = 0;
    struct in_addr address;
    
    for(int i=0; i<3; i++){
        ipv4 += bytes[i];
        ipv4 << 8;
    }
    ipv4 += bytes[3];

    address.s_addr = ipv4;

    return address;
}


int create_socket_fd(const char *addr, const char *port){
    int socket_file_descriptor;


    // Essa struct armazena informações de um host ou serviço 
    // em uma representação que é legível ao sistema operacional, 
    // ou seja, que pode ser utilizada pela API de socket. 
    // Para preencher essa struct é usada a função getaddrinfo.
    struct addrinfo hints;
    hints.ai_socktype = SOCK_STREAM;  // stream socket (orientado à conexão)
    hints.ai_family   = AF_INET;    // IPv4
    hints.ai_flags    = AI_PASSIVE;   // socket passivo (servidor) 
    
    // _____________________Craindo um objeto socket TCP/IP._____________________
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_file_descriptor == -1){
        raise_panic("socket creation failed.");
    }

    return socket_file_descriptor;
}


struct sockaddr_in binder(int socket_file_descriptor, uint16_t port){
    struct sockaddr_in addr;
    int bind_status;
    uint8_t big_endian_addr = {0,0,0,0};

    // _____________________Procedimento de bind._____________________
    addr.sin_family = AF_INET; // int
    addr.sin_port = port; // uint16_t
    addr.sin_addr = ipv4_addr(big_endian_addr); // uint32_t

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

