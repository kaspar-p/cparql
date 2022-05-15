#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "meta.h"
#include "table.h"
#include "execute.h"
#include "io.h"
#include "cparql.h"

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {
    if (strncmp(input_buffer->buffer, "insert", strlen("insert")) == 0) {
        statement->type = STATEMENT_INSERT;
        int args_assigned = sscanf(input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id), statement->row_to_insert.username, statement->row_to_insert.email);

        if (args_assigned < 3) {
            return PREPARE_SYNTAX_ERROR;
        }
        return PREPARE_SUCCESS;
    }

    if (strncmp(input_buffer->buffer, "select", strlen("select")) == 0) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNKNOWN_STATEMENT;
}

int main() {
    InputBuffer* input_buffer = new_input_buffer();
    Table* table = new_table();
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
        case (PREPARE_SYNTAX_ERROR):
            printf("Syntax error. Failed to parse statement.\n");
            break;
        case (PREPARE_UNKNOWN_STATEMENT):
            printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
            continue;
        }

        ExecuteResult result = execute_statement(&statement, table);
        switch (result) {
        case (EXECUTE_SUCCESS):
            printf("Executed statement type: %d.\n", statement.type);
            break;
        case (EXECUTE_TABLE_FULL):
            printf("Error, table full.\n");
            break;
        }
    }
}