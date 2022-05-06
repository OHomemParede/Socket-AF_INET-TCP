#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>

#include "../server/server.h"
#include "../utils/utils.h"
#include "./chat.h"

void communicate_send(char *buffer, char *payload, int socket_fd){
    uint16_t data_size;

    memset(buffer, '\x00', MAX_BUFFER_SIZE);
    strncpy(buffer, payload, MAX_BUFFER_SIZE);

    data_size = send(socket_fd, buffer, sizeof(buffer), 0);
    fprintf(
        stdout, 
        "%s[data_size: %d] < %s%s\n", 
        global_colors.cyan, 
        data_size,
        buffer, 
        global_colors.end
    );
}

void communicate_recv(char *buffer, int socket_fd){
    uint16_t data_size;

    memset(buffer, '\x00', MAX_BUFFER_SIZE);
    data_size = recv(socket_fd, buffer, sizeof(buffer), 0);
    fprintf(
        stdout, 
        "%s[data_size: %d] < %s%s\n", 
        global_colors.cyan, 
        data_size,
        buffer, 
        global_colors.end
    );
}

void host_chat(start_server_result_t sockets){
    char buffer[MAX_BUFFER_SIZE];

    communicate_recv(buffer, sockets.client_socket_fd);

    close(sockets.socket_fd);
    close(sockets.client_socket_fd);
}

void client_chat(int socket_fd){
    char buffer[MAX_BUFFER_SIZE];

    communicate_send(buffer, "ola!", socket_fd);

    close(socket_fd);
}