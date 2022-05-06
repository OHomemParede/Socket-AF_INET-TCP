
#define MAX_BUFFER_SIZE (1024 + 1)


/**
 * @brief send a msg
 * 
 * @param buffer socket buffer
 * @param payload input
 * @param socket_fd 
 */
void communicate_send(char *buffer, char *payload, int socket_fd);

/**
 * @brief receive a msg from a socket
 * 
 * @param buffer 
 * @param socket_fd 
 */
void communicate_recv(char *buffer, int socket_fd);

/**
 * @brief hosts a chat.
 * 
 * @param sockets 
 */
void host_chat(start_server_result_t sockets);

/**
 * @brief it is the clinte chat.
 * 
 * @param socket_fd 
 */
void client_chat(int socket_fd);
