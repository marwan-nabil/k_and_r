#include <stdio.h>

static char getch_buff[MAX_BUFF];
static unsigned int buff_ptr = 0;  /* points to next free position */

char getch()
{
  if(buff_ptr == 0)
    return getchar();
  else
    return getch_buff[--buff_ptr];
}

void ungetch(char c)
{
  if(buff_ptr >= MAX_BUFF)
    printf("\nError: ungetch(): ungetch buffer was exceded.\n");
  else
    getch_buff[buff_ptr++] = c;
}
