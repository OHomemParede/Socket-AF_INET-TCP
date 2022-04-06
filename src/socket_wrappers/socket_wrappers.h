#ifndef SOCKET_WRAPPERS_H
#define SOCKET_WRAPPERS_H

#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>


/**
 * @brief Create a socket fd object
 * 
 * @param addr - address
 * @param port - port
 */
create_socket_fd(const char *addr, const char *port);


/**
 * @brief receive four Bytes and returns a ipv4 32bits like,
 * in Big-endian notation.
 * 
 * @param bytes -
 * @return struct in_addr 
 */
struct in_addr ipv4_addr(uint8_t *bytes);


/**
 * @brief this operation is called “assigning a name to a socket”
 * 
 * @param socket_file_descriptor 
 * @param port is a int (0 - 2**16 -1)
 * @return struct sockaddr_in - addr
 */
struct sockaddr_in binder(int socket_file_descriptor, uint16_t port);


#endif