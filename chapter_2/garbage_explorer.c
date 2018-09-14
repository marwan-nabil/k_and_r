#include<stdio.h>

void garbage_explorer(){
  int i,d,t,r;    // uninitialized automatic variables
  printf("\nThis should be garbage values:%d %d %d %d\n",i,d,t,r);
}

void main(){
  garbage_explorer();
  return;
}
