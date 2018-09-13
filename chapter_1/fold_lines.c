#include<stdio.h>

void fold_line(int max){
  char c;
  int count;
  while((c = getchar()) != EOF && c != '*'){  // * is the end of input indicator
    count++;
    if(c == '\n'){
      c = ' ';
    }
    if(count >= max){
      printf("\n%c", c);
      count = 0;
    } else {
      printf("%c",c);
    }
  }
}

int main(){
  fold_line(20);
  return 0;
}
