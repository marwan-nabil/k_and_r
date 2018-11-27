#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tokens.h"

/* get_token: formats input string into unchecked tokens */
token get_token()
{
  token t;
  char c;
  int i = 0;
  // skip leading white spaces
  while((c = getch()) == ' ' || c == '\t')
    ;
  t.value[i++] = c;
  // tokenize on whitespaces
  for(; c != ' ' && i < MAX_TOKEN-1; i++)
    t.value[i] = c;

  ungetch(' ');    // this splits long tokens into multiple tokens as a side effect
                   // and only the last (less than maximum) part of these long tokens
                   // is treated as a valid token.
  t.value[i] = '\0'; // null termination of all strings
  t.type = UNK;    // type is determined later in token checking.

  // check token length for too long tokens
  if(i >= MAX_TOKEN - 1){
    printf("\nError: get_token(): input token is too long.\n");
    // the token is discarded and replaced by error values
    t.value = ERR_VAL;
    t.type = ERR_TYPE;
  }
  return t;
  // we won't check for malformed tokens here
}

token check_token(token t)
{
  // if the token has error value or type, exit without warning
  // the error has already been reported
  if(t.type == ERR_TYPE || t.value == ERR_VAL)
    exit(1);

  // check numeric value
  if(isdigit(t.value[0]) || t.value[0] == '-'){
    // check the whole number for non-numeric stuff
    for(int i=1; t.value[i] != '\0'; i++){
      if(!isdigit(t.value[i]) && t.value[i] != '.'){
	printf("\nError: check_token(): malformed numeric value.");
	t.value = ERR_VAL;
	t.type = ERR_TYPE;
	exit(1);
      }
    }
    // if the number is good return the token with NUM type
    t.type = NUM;
    return t;
  }
  else if(t.value[0] >= 'a' && t.value[0] <= 'z'){
    t.type = VARIABLE;
    return t;
  }
  else if(isFunction(t.value)){
    t.type = FUNCTION;
    return t;
  }
  else if(isOperator(t.value[0])){
    t.type = OPERATOR;
    return t;
  }
  else{
    printf("\nError: check_token(): Unknown token type.");
    exit(1);
  }
}

double atof(char *str)
{
  double val, pow;
  int i, sign;
  for(i = 0; isspace(str[i]); i++)
    ;
  sign = (str[i] == '-' ? -1 : 1);
  if (str[i]=='-' || str[i]=='+')
    i++;
  for(val = 0.0F; isdigit(str[i]); i++)
    val = 10*val + (str[i]- '0');
  if(str[i]=='.')
    i++;
  for(pow = 1.0F; isdigit(str[i]); i++){
    pow = pow*10 ;
    val = val*10 + (str[i]-'0');
  }
  return val*sign/pow;  
}

int isOperator(char c)
{
  if(c == '+' || c == '-' || c == '/' || c == '*' || c == '%')
    return 1;
  else
    return 0;
}

int isFunction(char *s)
{
  char sc[4];
  strncpy(sc, s, 3); // copy the function code (first 3 characters)
  sc[3] = '\0';
  if(strcmp(sc, "sin") || strcmp(sc, "cos"))
    return 1;
  else
    return 0;
}
