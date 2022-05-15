#ifndef _EXECUTE_H_INCLUDED_
#define _EXECUTE_H_INCLUDED_

#include "table.h"

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct {
    Row row_to_insert;
    StatementType type;
} Statement;

typedef enum {
    EXECUTE_SUCCESS,
    EXECUTE_TABLE_FULL
} ExecuteResult;

ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);
ExecuteResult execute_statement(Statement* statement, Table* table);

#endif /* _EXECUTE_H_INCLUDED_ */