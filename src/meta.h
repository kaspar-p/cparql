#ifndef _META_H_INCLUDED_
#define _META_H_INCLUDED_

#include "io.h"

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNKNOWN_COMMAND,
} MetaCommandResult;

void process_meta_command(InputBuffer* input_buffer);
MetaCommandResult do_meta_command(InputBuffer* input_buffer);

#endif /* _META_H_INCLUDED_ */