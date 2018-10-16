#include<ctype.h>
#include<stdio.h>

float atof(char *str)
{
  float val, pow;
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

int main()
{
  char s[20];
  printf("\nEnter a decimal number: ");
  scanf("%s", s);
  printf("\nthe number in float is: %f\n", atof(s));
}
