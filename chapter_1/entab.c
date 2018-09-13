#include<stdio.h>

void entab(){
  int spaces;
  char c;

  while((c = getchar()) != EOF && c != '\n'){
    if(c == ' ')
      spaces += 1;
    if(spaces != 4)
      printf("%c",c);
    else {
      printf("\t");
      spaces = 0;
    }
  }
}

int main(){
  entab();
  return 0;
}
