#include <stdio.h>
#include "stack.h"

int main(){
  // NOTE: set the stack size to 5 (small enough to test error stuff) in stack.h
  // test: simple push then pop
  printf("\nTest: pushing a number and then popping.\n");
  stack_element e;
  e.value = 23.4L;
  e.type = NUM;
  push(e);
  printf("\nvalue pushed was: %f.\n", pop().value);
  
  // test: stack overflowing trial
  printf("\nTest: stack overflowing.\n");
  for(int i=0; i <= STACK_SIZE; i++)
    push(e);

  // test: stack underflowing trial
  printf("\nTest: stack underflowing.\n");
  for(int i=0; i <= STACK_SIZE; i++)
    pop();

  // test: duplicating a small stack
  printf("\nTest: duplicating in a small stack.\n");
  clear_stack();
  push(e);
  push(e);
  push(e);
  duplicate_stack();

  // test peeking then popping
  printf("\nTest: peeking then poping.\n");
  clear_stack();
  push(e);
  printf("\npeeked value: %f.\n", peek().value);
  printf("\nPopped value: %f.\n", pop().value);

  // test: dumping stack to stdout
  printf("\nTest: dumping stack to stdout.\n");
  clear_stack();
  e.value = '+';
  e.type = OPERATOR;
  push(e);
  e.value = '-';
  e.type = OPERATOR;
  push(e);
  e.value = 23.5657;
  e.type = NUM;
  push(e);
  e.value = 'f';
  e.type = VARIABLE;
  push(e);
  dump_stack();
}
