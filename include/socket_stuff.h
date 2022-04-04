#ifndef SOCKET_STUFF_H
#define SOCKET_STUFF_H

#include <stdint.h>
#include <netinet/in.h>


/**
 * @brief Create a socket fd object
 * 
 * @return int - socket_file_descriptor
 */
int create_socket_fd();


/**
 * @brief receive four Bytes and returns a ipv4 32bits like.
 * 
 * @param oct1 
 * @param oct2 
 * @param oct3 
 * @param oct4 
 * @return struct in_addr - address
 */
struct in_addr ipv4_addr(uint8_t oct1, uint8_t oct2, uint8_t oct3, uint8_t oct4);


/**
 * @brief this operation is called “assigning a name to a socket”
 * 
 * @param socket_file_descriptor 
 * @param port is a int (0 - 2**16 -1)
 * @return struct sockaddr_in - addr
 */
struct sockaddr_in do_a_bind(int socket_file_descriptor, uint16_t port);


#endif