#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct {
  FILE *file;
  long long int line_count;
  long long int byte_count;
  pthread_mutex_t mutex;
} SharedData;

void *count_lines(void *arg) {
  SharedData *data = (SharedData *)arg;
  char buffer[BUFFER_SIZE];
  long long int local_line_count = 0;

  while (fgets(buffer, BUFFER_SIZE, data->file) != NULL) {
    local_line_count++;
  }

  pthread_mutex_lock(&data->mutex);
  data->line_count += local_line_count;
  pthread_mutex_unlock(&data->mutex);

  return NULL;
}

void *count_bytes(void *arg) {
  SharedData *data = (SharedData *)arg;
  char buffer[BUFFER_SIZE];
  int64_t local_byte_count = 0;

  fseek(data->file, 0, SEEK_SET);

  while (fgets(buffer, BUFFER_SIZE, data->file) != NULL) {
    local_byte_count += strlen(buffer);
  }

  pthread_mutex_lock(&data->mutex);
  data->byte_count += local_byte_count;
  pthread_mutex_unlock(&data->mutex);

  return NULL;
}

int main() {
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  SharedData data;
  data.file = file;
  data.line_count = 0;
  data.byte_count = 0;
  pthread_mutex_init(&data.mutex, NULL);

  pthread_t line_thread, byte_thread;

  if (pthread_create(&line_thread, NULL, count_lines, &data) != 0) {
    perror("Error creating line thread");
    return EXIT_FAILURE;
  }

  if (pthread_create(&byte_thread, NULL, count_bytes, &data) != 0) {
    perror("Error creating byte thread");
    return EXIT_FAILURE;
  }

  pthread_join(line_thread, NULL);
  pthread_join(byte_thread, NULL);

  fclose(file);
  pthread_mutex_destroy(&data.mutex);

  printf("%lld lines, %lld bytes\n", data.line_count, data.byte_count);
  return EXIT_SUCCESS;
}
