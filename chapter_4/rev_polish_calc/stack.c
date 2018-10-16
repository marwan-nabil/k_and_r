/* this file defines a stack (an external array)
 * and operations on it, namely: pop, push, peek, clear
 * duplicate, swap top two.
 */
#include <stdio.h>
#include "stack.h"

static stack_element stack[STACK_SIZE];
static int stack_pointer = 0;  /* points to the first free stack position */

/* push */
void push(stack_element in)
{
  if(stack_pointer >= STACK_SIZE)
    fprintf(stderr, "\nERROR: push(): stack is full.\n");
  else
    stack[stack_pointer++] = in;
}

/* pop */
stack_element pop()
{
  if(stack_pointer <= 0){
    fprintf(stderr, "\nERROR: pop(): stack is empty.\n");
    stack_element e = {0.0L, NUL};
    return e;
  }
  else{
    return stack[--stack_pointer];
  }
}

/* peek */
stack_element peek()
{
  if(stack_pointer <= 0){
    fprintf(stderr, "\nERROR: peek(): stack is empty.\n");
    stack_element e = {0.0L, NUL};
    return e;
  }
  else{
    return stack[stack_pointer-1];
  }
}

/* clear */
void clear_stack()
{
  stack_pointer = 0;
}

/* duplicate stack */
void duplicate_stack()
{
  if(stack_pointer >= STACK_SIZE / 2)
    fprintf(stderr, "\nERROR: duplicate_stack(): stack is not big enough.\n");
  else{
    for(int i=0; i<stack_pointer; i++){
      stack[i+stack_pointer]=stack[i];
    }
    stack_pointer *= 1;
  }
}

/* swap top two elements */
void swap_top_two()
{
  stack_element temp = stack[stack_pointer-1];
  stack[stack_pointer-1] = stack[stack_pointer-2];
  stack[stack_pointer-2] = temp;
}

/* dump stack to stdin */
void dump_stack()]
{
  printf("\nDumping stack contents...\n"
	 "\ttype\t|\tvalue\n");

  for(int i=0; i<stack_pointer; i++){
    char *type;
    switch(stack[i].type){
    case NUM:
      type = "number";
      break;
    case OPERATOR:
      type = "operator";
      break;
    case VARIABLE:
      type = "variable";
      break;
    default:
      type = "null";
      break;
    }
    printf("\t%s\t%f\n", type, stack[i].value);
  }
}
