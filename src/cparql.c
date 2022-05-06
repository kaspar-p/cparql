#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "io.h"
#include "meta.h"

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNKNOWN_STATEMENT
} PrepareResult;


typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct {
    StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {
    if (strncmp(input_buffer->buffer, "insert", strlen("insert")) == 0) {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    if (strncmp(input_buffer->buffer, "select", strlen("select")) == 0) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNKNOWN_STATEMENT;
}

void execute_statement(Statement* statement) {
    switch (statement->type) {
    case (STATEMENT_INSERT):
        printf("Doing an insert!\n");
        break;
    case (STATEMENT_SELECT):
        printf("Doing a select!\n");
        break;
    }
}

int main() {
    InputBuffer* input_buffer = new_input_buffer();
    while (true) {
        print_prompt();
        read_input(input_buffer);
        // Process a meta command (starts with .)
        if (strncmp(input_buffer->buffer, ".", 1) == 0) {
            process_meta_command(input_buffer);
            continue;
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
        case (PREPARE_SUCCESS):
            break;
        case (PREPARE_UNKNOWN_STATEMENT):
            printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
            continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
    }
}