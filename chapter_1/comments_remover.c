#include<stdio.h>

void remove_comments(){
  char c, t;
  while((c = getchar()) != EOF){
    if(c == '/' && (t = getchar()) == '*'){ /* you're in a comment, skip it */
      while(getchar() != '*') ;
      getchar();
      c = getchar();
    } else if(c == '/'){  /* a simple '/' */
      ungetc(t, stdin);
    }
    
    printf("%c", c);
  }
}

int main(){
  remove_comments();
  return 0;
}
