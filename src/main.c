#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define PROJECT_NAME "simpledb"

/**
 * InputBuffer:
 *
 * Wrapper to store state necessary for interacting with getline
 */
typedef struct {
  char *buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

/**
 * new_input_buffer:
 *
 * Constructor for InputBuffer
 */
InputBuffer *new_input_buffer() {
  InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;
  return input_buffer;
}

/**
 * print_prompt:
 *
 * Shows prompt to user
 */
void print_prompt() { printf("db > "); }
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/**
 * read_input
 *
 * Store user input into an instance of InputBuffer
 */
void read_input(InputBuffer *input_buffer) {
  ssize_t bytes_read =
      getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  // Ignore trailing newline
  input_buffer->input_length = bytes_read - 1;
  input_buffer->buffer[bytes_read - 1] = 0;
}

/**
 * close_input_buffer:
 *
 * Frees allocated memory for an instance of InputBuffer
 */
void close_input_buffer(InputBuffer *input_buffer) {
  free(input_buffer->buffer);
  free(input_buffer);
}

/**
 * evaluate_buffer:
 *
 * Evaluate user query
 */
void evaluate_buffer(InputBuffer *input_buffer) {
  if (strcmp(input_buffer->buffer, ".exit") == 0) {
    close_input_buffer(input_buffer);
    exit(EXIT_SUCCESS);
  } else {
    printf("Unrecognized command '%s'.\n", input_buffer->buffer);
  }
}

int main() {
  InputBuffer *input_buffer = new_input_buffer();
  while (true) {
    print_prompt();
    read_input(input_buffer);
    evaluate_buffer(input_buffer);
  }
}
