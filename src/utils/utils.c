#include <stdlib.h>
#include <stdio.h>

#include "./utils.h"

colors_t global_colors = {
  .end = "\033[0m",
  .black = "\033[0;30m",
  .red = "\033[0;31m",
  .green = "\033[0;32m",
  .yellow = "\033[0;33m",
  .blue = "\033[0;34m",
  .purple = "\033[0;35m",
  .cyan = "\033[0;36m",
  .white = "\033[0;37m"
};

void raise_panic(char *error_msg) {
  fprintf(stderr, "%sError: { %s }%s\n", global_colors.red, error_msg, global_colors.end);
  exit(EXIT_FAILURE);
}
