#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>

#include "../server/server.h"
#include "../utils/utils.h"
#include "./chat.h"

void communicate_send(char payload[MAX_BUFFER_SIZE], int socket_fd){
    uint16_t data_size;

    data_size = send(socket_fd, payload, strlen(payload), 0);
    fprintf(
        stdout, 
        "%s[data_size: %d] -> %s%s\n", 
        global_colors.cyan, 
        data_size,
        payload, 
        global_colors.end
    );
}

void communicate_recv(char buffer[MAX_BUFFER_SIZE], int socket_fd){
    uint16_t data_size;

    memset(buffer, '\x00', MAX_BUFFER_SIZE);
    data_size = recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0);
    fprintf(
        stdout, 
        "%s[data_size: %d] <- %s%s\n", 
        global_colors.purple, 
        data_size,
        buffer, 
        global_colors.end
    );
}

void host_chat(start_server_result_t sockets){
    char buffer[MAX_BUFFER_SIZE];
    char payload[MAX_BUFFER_SIZE];

    memset(payload, '\x00', MAX_BUFFER_SIZE);
    memset(buffer, '\x00', MAX_BUFFER_SIZE);

    while(TRUE){

        do {
            communicate_recv(buffer, sockets.client_socket_fd);
            if(strn_equals(buffer, "!u", 2) || strn_equals(buffer, "!end", 4))
                break;
            sleep(1);
        }
        while(TRUE);
        if(strn_equals(buffer, "!end", 4)) {
            fprintf(
                stdout,
                "%sConnection closed by client.%s\n",
                global_colors.red,
                global_colors.end
            );
            break;
        }

        do {
            memset(payload, '\x00', MAX_BUFFER_SIZE);
            fprintf(stdout, "> ");
            fgets(payload, MAX_BUFFER_SIZE, stdin);
            communicate_send(payload, sockets.client_socket_fd);

            if(strn_equals(payload, "!u", 2) || strn_equals(payload, "!end", 4))
                break;
        }
        while(TRUE);
        if(strn_equals(payload, "!end", 4)) {
            fprintf(
                stdout,
                "%sConnection closed.%s\n",
                global_colors.red,
                global_colors.end
            );
            break;
        }
    }
    close(sockets.socket_fd);
}

void client_chat(int socket_fd){
    char buffer[MAX_BUFFER_SIZE];
    char payload[MAX_BUFFER_SIZE];

    memset(payload, '\x00', MAX_BUFFER_SIZE);
    memset(buffer, '\x00', MAX_BUFFER_SIZE);

    while(TRUE){

        do {
            memset(payload, '\x00', MAX_BUFFER_SIZE);
            fprintf(stdout, "> ");
            fgets(payload, MAX_BUFFER_SIZE, stdin);
            communicate_send(payload, socket_fd);

            if(strn_equals(payload, "!u", 2) || strn_equals(payload, "!end", 4))
                break;
        }
        while(TRUE);
        
        if(strn_equals(payload, "!end", 4)) {
            fprintf(
                stdout,
                "%sConnection closed.%s\n",
                global_colors.red,
                global_colors.end
            );
            break;
        }

        do{
            communicate_recv(buffer, socket_fd);
            if(strn_equals(buffer, "!u", 2) || strn_equals(buffer, "!end", 4))
                break;
            sleep(1);
        }
        while(TRUE);
        if(strn_equals(buffer, "!end", 4)) {
            fprintf(
                stdout,
                "%sConnection closed by server.%s\n",
                global_colors.red,
                global_colors.end
            );
            break;
        }
    }
    close(socket_fd);
}