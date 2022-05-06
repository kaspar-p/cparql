#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "io.h"

InputBuffer* new_input_buffer() {
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    if (input_buffer == NULL) {
        perror("Input buffer malloc failed!");
        exit(EXIT_FAILURE);
    }

    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}

void read_input(InputBuffer* input_buffer) {
    // Read from stdin
    ssize_t n_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
    if (n_read <= 0) {
        printf("Error reading input!\n");
        exit(EXIT_FAILURE);
    }

    // Ignore trailing newline
    input_buffer->input_length = n_read - 1;
    input_buffer->buffer[input_buffer->input_length] = '\0';
}

void print_prompt() {
    printf("cparql ::: ");
}