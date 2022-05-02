#include <stdint.h>

#include "./server/server.h"

int main(){
    uint8_t host[4] = {127, 0, 0, 1};

    start_server(host, 9001);
    return 0;
}
