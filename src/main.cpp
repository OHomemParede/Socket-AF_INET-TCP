#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <netinet/in.h>

in_addr ipv4_addr(uint8_t oct1, uint8_t oct2, uint8_t oct3, uint8_t oct4);

in_addr ipv4_addr(uint8_t oct1, uint8_t oct2, uint8_t oct3, uint8_t oct4){
    in_addr_t sum = 0;
    in_addr address;
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

int main(){

    int socket_file_descriptor, bind_status;
    struct sockaddr_in addr;

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
     * 
     */
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_file_descriptor == -1){
        printf("socket creation failed... - socket_file_descriptor value: %d\n", socket_file_descriptor);
        exit(EXIT_FAILURE);
    }
    printf("Socket successfully created... - socket_file_descriptor value: %d\n", socket_file_descriptor);


    // _____________________Procedimento de bind._____________________
    addr.sin_family = AF_INET;
    addr.sin_port = 1337;
    addr.sin_addr = ipv4_addr(0, 0, 0, 0);

    bind_status = bind(socket_file_descriptor, (struct sockaddr *)&addr, sizeof(addr));
    if (bind_status != 0) {
        printf("socket bind failed... - bind_status: %d\n", bind_status);
        exit(EXIT_FAILURE);
    }
    printf("Socket successfully binded... - bind_status: %d\n", bind_status);

    int input;
    do {
        std::cin >> input;
    } while (input != 0);

    return 0;
}
