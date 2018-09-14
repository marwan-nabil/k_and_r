#include<stdio.h>
#include<limits.h>

void char_limits(){
  unsigned char uc, uc_max;
  signed char sc,sc_max;
  uc = 1;
  sc = 0;
  // unsigned range determination
  while(uc > 0)
    uc_max = uc++;
  printf("\nMaximum unsigned char is : %d", uc_max);

  // signed range calculations
  while(sc >= 0)
    sc_max = sc++;
  printf("\nMaximum signed char is : %d", sc_max);
  printf("\nMinimum signed char is : %d",  sc);
}


void main(){
  char_limits();
}
