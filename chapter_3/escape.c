#include<stdio.h>
#define MAX 2000
void escape(char *s, char *t){
  int i,j;
  for (i=0, j=0; t[i] != '\0'; i++, j++){
    switch(t[i]){
    case '\n':
      s[j++]='\\';
      s[j]='n';
      break;
    case '\t':
      s[j++]='\\';
      s[j]='t';
      break;
    default:
      s[j]=t[i];
      break;
    }
  }

  s[i] = '\0';
  return;
}

int main(int argc, char **argv){
  FILE *f = fopen(argv[1], "r");
  printf("\nOpening file %s for reading ...", argv[1]);
  char t[MAX];
  int num_read = fread(t,1,MAX,f);
  char s[2*MAX];
  escape(s,t);
  printf("\nPrinting the result of the program...\n");
  puts(s);
  return 0;
}
