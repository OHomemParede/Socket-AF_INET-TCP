#ifndef SOCKET_WRAPPERS_H
#define SOCKET_WRAPPERS_H

#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>


/**
 * @brief Create a socket fd object
 * 
 * @return socket file descriptor
 */
int create_socket_fd();


/**
 * @brief receive four Bytes and returns a ipv4 32bits like,
 * in Big-endian notation.
 * 
 * @param bytes is a vector of size 4 
 * @return struct in_addr 
 */
struct in_addr get_ipv4_addr(uint8_t host[4]);


/**
 * @brief Get the addr object
 * 
 * @param host address ipv4
 * @param port is a in range of (0 - 2**16 -1)
 * @return struct sockaddr_in 
 */
struct sockaddr_in get_addr(u_int8_t host[4], uint16_t port);


/**
 * @brief this operation is called “assigning a name to a socket”
 * 
 * @param socket_fd 
 * @param addr
 */
void binder(int socket_fd, struct sockaddr_in addr);


/**
 * @brief just run socket listen 
 * 
 * @param socket_fd 
 * @param queue 
 */
void start_listen(int socket_fd, int queue);

#endif