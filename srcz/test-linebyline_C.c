#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  long lineCount = 0;
  long byteCount = 0;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) {
    lineCount++;
    byteCount += read;
  }

  if (ferror(file)) {
    perror("Error reading file");
    free(line);
    fclose(file);
    return EXIT_FAILURE;
  }

  printf("%ld lines, %ld bytes\n", lineCount, byteCount);

  free(line);
  fclose(file);
  return EXIT_SUCCESS;
}
