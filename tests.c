#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cotenv.h"

void create_temp_env_file(const char *filename) {
  FILE *file = fopen(filename, "w");
  if (!file) {
    cotenv_failed_to_create_file(filename);
    exit(EXIT_FAILURE);
  }

  fprintf(file, "HELLO_WORLD=HelloWorld\n");
  fprintf(file, "MEANING_OF_LIFE=42\n");
  fprintf(file, "# This is an usefull commment\n");
  fprintf(file, "NAME_OF_GIRLFRIEND=\n");
  fclose(file);
}

void test(const char *test, const char *expected) {
  if (test && strcmp(test, expected) == 0) {
    printf("Test passed: %s\n", test);
  } else {
    printf("Test failed: %s\n", test);
  }
}

void run_tests() {
  const char *test_file = "test.env";

  create_temp_env_file(test_file);

  load_cotenv(test_file);

  const char *hello_world = getenv("HELLO_WORLD");
  const char *meaning_of_life = getenv("MEANING_OF_LIFE");
  const char *name_of_girlfriend = getenv("NAME_OF_GIRLFRIEND");

  test(hello_world, "HelloWorld");
  test(meaning_of_life, "42");
  test(name_of_girlfriend, "\n");

  remove(test_file);
}

int main() {
  run_tests();
  return EXIT_SUCCESS;
}
