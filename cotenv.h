#ifndef COTENV_H
#define COTENV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_KEY_LENGTH 128
#define MAX_VALUE_LENGTH 128

static char *trim_whitespace(char *str) {
  char *end;

  while (*str == ' ' || *str == '\t') str++;

  end = str + strlen(str) - 1;
  while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) end--;

  *(end + 1) = '\0';
  
  return str;
}

static void cotenv_failed_to_open_file(const char *filename) {
  fprintf(stderr, "Failed to open %s file", filename);
}

static void cotenv_failed_to_create_file(const char *filename) {
  fprintf(stderr, "Failed to create temporary %s file" , filename);
}

static void cotenv_failed_env_var(const char *key) {
  fprintf(stderr, "Failed to set %s variable", key);
}

int load_cotenv(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    cotenv_failed_to_open_file(filename);
    return -1;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, sizeof(line), file)) {
    if (line[0] == '#' || line[0] == '\n') {
      continue;
    }

    char *key = strtok(line, "=");
    char *value = strtok(NULL, "\n");

    if (key && value) {
      key = trim_whitespace(key);
      value = trim_whitespace(value);
      if(setenv(key, value, 1) != 0) {
        cotenv_failed_env_var(key);
	fclose(file);
	return -1;
      }
    }
  }

  fclose(file);
  return 0;
}


#endif
