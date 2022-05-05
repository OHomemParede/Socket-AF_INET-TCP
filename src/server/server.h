#include <stdint.h>
#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

typedef struct start_server_result {
    int socket_fd;
    int client_socket_fd;
} start_server_result_t;

/**
 * @brief Starts a server on host:port
 * 
 * @param host 
 * @param port 
 * @return start_server_result_t 
 */
start_server_result_t start_server(uint8_t host[4], uint16_t port);

#endif