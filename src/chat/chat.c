#include <unistd.h>
#include <stdint.h>
#include <string.h>

void run_chat(socket){

// ================= cht protocol =======
    char buffer[5];
    uint16_t data_size;

    // recv hi
    memset(buffer, '\x00', sizeof(buffer));
    data_size = recv(sockets_fd.client_socket_fd, buffer, sizeof(buffer), 0);
    fprintf(stdout, "%s[data_size: %d] < %s%s\n", global_colors.cyan, data_size, buffer, global_colors.end);

    // send hi
    memset(buffer, '\x00', sizeof(buffer));
    buffer[0] = 'B';
    data_size = send(sockets_fd.client_socket_fd, buffer, strlen(buffer), 0);
    fprintf(stdout, "[data_size: %d] > %s\n", data_size, buffer);

    // recv whatever
    memset(buffer, '\x00', sizeof(buffer));
    data_size = recv(sockets_fd.client_socket_fd, buffer, sizeof(buffer), 0);
    fprintf(stdout, "[data_size: %d] < %s\n", data_size, buffer);

    
    close(sockets_fd.socket_fd);
}