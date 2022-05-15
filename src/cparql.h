#ifndef _CPARQL_H_INCLUDED_
#define _CPARQL_H_INCLUDED_

#include "io.h"

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNKNOWN_STATEMENT
} PrepareResult;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
int main();

#endif /* _CPARQL_H_INCLUDED_ */