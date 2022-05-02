#include <stdint.h>
#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

/**
 * @brief Starts a server on host:port
 * @param host
 * @param port
 */
void start_server(uint8_t host[4], uint16_t port);

#endif