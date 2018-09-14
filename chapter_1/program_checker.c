/*
the program should check a c source file for unmatched symbols, 
like parantheses or braces.
also should check for arbitrary syntax errors.
*/
#include<stdio.h>
#include<string.h>

#define STACKMAX 30
char stack[STACKMAX];
char *stack_p = stack;

void push(char c){
  *stack_p++ = c;
}
char pop(){
  return *(--stack_p);
}
char peek(int i){
  return *(stack_p - i);
}


char *left_paren =  "<({[";
char *right_paren = ">)}]";

typedef enum {LEFT, RIGHT, NOT_PAREN} paren_type_t;
typedef enum {UNKNOWN, CURLYS, BRACES, BRACKS, ANGLED} paren_class_t;

paren_type_t what_paren_type(char s)
{
  if(strchr(left_paren, s))
    return LEFT;
  else if(strchr(right_paren, s))
    return RIGHT;
  else
    return NOT_PAREN;
}

paren_class_t what_paren_class(char c)
{
  if(c=='<' || c=='>')
    return ANGLED;
  else if(c == '[' || c==']')
    return BRACKS;
  else if(c=='(' || c==')')
    return BRACES;
  else if(c=='{' || c=='}')
    return CURLYS;
  else
    return UNKNOWN;
}

void check_program(void)
{
  char c;
  paren_type_t t;
  paren_class_t cl;

  while((c = getchar())!= EOF){
    t = what_paren_type(c);

    if(t == NOT_PAREN)
      printf("%c",c);
    else if(t == LEFT){
      push(c);
      printf("%c",c);
    }
    else if(t == RIGHT){
      if(what_paren_class(c) != what_paren_class(peek(1))){
	printf("%c",c);
	printf("  << Syntax error: unmatched parens\n");
	return ;
      }
      else{
	printf("%c",c);
	pop();
      }
    }
  }
}

int main()
{
  check_program();
}
