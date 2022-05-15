#ifndef _IO_H_INCLUDED_
#define _IO_H_INCLUDED_

#include <stdio.h>
#include "table.h"

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void print_prompt();
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);
void print_row(Row* row);

#endif /* _IO_H_INCLUDED */