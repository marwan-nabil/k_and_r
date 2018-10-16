#define STACK_SIZE 5
#include "tokens.h"

#ifndef __stack_h_
#define __stack_h_

void swap_top_two();
void duplicate_stack();
void clear_stack();
token peek();
token pop();
void push(token in);
void dump_stack();

#endif
