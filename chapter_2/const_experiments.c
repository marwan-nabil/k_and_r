#include<stdio.h>

void main(){
  char str[]= "aaa";
  str[1] = 'd';
  printf("%s", str);

  const char str2[]= "aaa";
  str2[1] = 'b';    // error
  printf("%s",str2);
}
