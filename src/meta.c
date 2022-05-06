#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "io.h"
#include "meta.h"

void process_meta_command(InputBuffer* input_buffer) {
    switch (do_meta_command(input_buffer)) {
    case (META_COMMAND_SUCCESS):
        return;
    case (META_COMMAND_UNKNOWN_COMMAND):
        printf("Unknown command: '%s'.\n", input_buffer->buffer);
        return;
    }
}

MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
        close_input_buffer(input_buffer);
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNKNOWN_COMMAND;
    }
}