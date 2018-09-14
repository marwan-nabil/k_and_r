/* convert a hex value: 34af or 0x34AF into an integer */
#include<stdio.h>

int htoi(const char *hex){
  char *str = hex;
  int n = 0;

  /* skip leading "0x" */
  if(str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
    str += 2;

  for(int i=0; str[i]!='\0' ; i++){
    if(str[i] >= '0' && str[i] <= '9') // decimal digit case
      n = n*16 + str[i]-'0';
    else if(str[i] >= 'a' && str[i] <= 'f')
      n = n*16 + str[i]-'a' + 10;
    else if(str[i] >= 'A' && str[i] <= 'F')
      n = n*16 + str[i]-'A' + 10;
    else{
      printf("\nError: bad hex value.\n");
      return NULL;
    }
  }

  return n;
}

void main(){
  char str[20];
  printf("\nEnter a hex value to be converted to an int: ");
  scanf("%s", str);
  int n = htoi(str);
  printf("\nThe entered number as an int is : %d", n);
  return ;
}
