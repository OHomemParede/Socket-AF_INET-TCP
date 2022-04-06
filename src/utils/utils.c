#include <stdlib.h>
#include <stdio.h>

#include "./utils.h"

void rise_panic(const char* error_msg) {
  fprintf(stderr, "Error: { %s }\n", error_msg);
  exit(EXIT_FAILURE);
}