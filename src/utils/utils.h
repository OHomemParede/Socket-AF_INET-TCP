#ifndef SOCKET_CHAT_UTILS_H
#define SOCKET_CHAT_UTILS_H

#define TRUE 1
#define FALSE 2

/**
 * @brief output error_msg to stderr and exit program with code 1.
 * 
 * @param error_msg 
 */
void raise_panic(char *error_msg);

#endif