#include <stdint.h>
#include <string.h>

#include "./server/server.h"
#include "./client/client.h"

int main(int argc, char **argv){
    uint8_t host[4] = {127, 0, 0, 1};

    if(!strncmp(argv[1], "server", 6)){
        start_server(host, 9001);

    }

    if(!strncmp(argv[1], "client", 6)){
        start_client(host, 9001);

    }
    return 0;
}
