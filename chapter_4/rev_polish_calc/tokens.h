/* a token is a contiguous string (doesn't include whitespaces)
 * associated with a type (interpretation), example tokens with (types):
 * 324.24 (NUMber)   
 * + (OPERATOR)
 * -34 (NUMber)
 * a (VARIABLE)
 * sin(32) (FUNCTION)
 * '\0' (NUL) error value, used internally to indicate malformed token
 * [any value] (UNK) indicates that the value is still unchecked, used internally
 */
#ifndef __token_h_
#define __token_h_

#define MAX_TOKEN  20    /* maximum length of the token value string */
#define ERR_VAL "ERROR"  /* error value for tokens */
#define ERR_TYPE NUL     /* error type for tokens */

enum token_type{NUM, OPERATOR, VARIABLE, FUNCTION, NUL, UNK};

// the type field helps the calculator deal with the value of the token
typedef struct{
  char value[MAX_TOKEN];
  enum token_type type;
} token;

// gets a token from stdin stream and checks if it's too long
// then returns the token for further checking
token get_token();

// checks a token for erroneous values, determines its type
// and returned a typed token, that can be later processed by the calculator
token check_token(token);

// check if a character is a valid operator
int isOperator(char);

// checks if a string is a valid trignometric function
int isFunction(char *);
// converts a string into a double
double atof(char *str);

#endif
