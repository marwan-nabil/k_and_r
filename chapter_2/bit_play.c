#include<stdio.h>
/* function set_bits(x,p,n,y) returns x with the
 * n bits beginning at position p set to the rightmost
 * n bits of y, with the rest unchanged. 
 */

unsigned int set_bits(unsigned x, int p, int n, unsigned y){
  unsigned y_part = y & ~(~0 << n);
  unsigned y_part_aligned = y_part << (p - n + 1);
  unsigned mask = (~(~0 << n))<< (p - n + 1); // 000011110000000
  return ( x & ~mask ) ^ y_part_aligned;
}

/* inverts n bits at p position from x */
unsigned invert(unsigned x, int p, int n){
  unsigned mask = (~(~0 << n))<<(p-n+1);      // 0000111000000
  return x ^ mask;
}


/* does unsigned right rotation */
unsigned right_rot(unsigned x, int n){
  unsigned rot_bits = x & ~(~0<<n);
  return (x >> n) ^ (rot_bits << (sizeof(unsigned)*8 - n));
}

/* counts how many 1 bits in x */
int bitcount(unsigned x){
  int b;
  for(b = 0; x != 0; x>>1){
    if(x && 1)
      b++;
  }
  return b;
}

void main(){
  while(1){
    printf("\nEnter a number (i): ");
    unsigned i;
    scanf("%d", &i);
    printf("\the number after set_bits(i, 3, 2, 5) is: %d\n", set_bits(i,3,2,5));
  }
}
