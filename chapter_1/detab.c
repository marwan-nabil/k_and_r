#include<stdio.h>

void detab(){
  char c;
  while((c = getchar()) != '\0' && c != EOF){
    if( c == '\t')
      printf("    ");
    else
      printf("%c",c);
  }
}

int main(int argc, char **argv){
  detab();
}
  
