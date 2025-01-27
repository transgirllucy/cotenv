#include "cotenv.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
  load_cotenv(".env");

  const char *world = getenv("WORLD");

  printf("Hello %s\n", world);

  return EXIT_SUCCESS;
}
