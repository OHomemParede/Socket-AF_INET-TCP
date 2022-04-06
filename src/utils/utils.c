#include <stdlib.h>
#include <stdio.h>

void panic(const char* error_msg) {
  fprintf(stderr, "Error: { %s }\n", error_msg);
  exit(EXIT_FAILURE);
}