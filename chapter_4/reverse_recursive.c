/* This program reverses a string in place using a recursive function */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 20
/* swap as a macro is faster than a function call */
#define swap(str, a, b)  { char tmp = str[b];  str[b] = str[a];	str[a] = tmp; }

void reverse_str(char *str, unsigned int length)
{
	if (length <= 1)				/* return if this is the middle char in an odd length string */
		return;

	swap(str, 0, length-1);			/* swap first and last chars */
	reverse_str(str+1, length-2);	/* Note: Stack doesn't grow */
}

int main()
{
	char str[MAXSTR];

	printf("\nPlease enter a string of %d characters max: ", MAXSTR);
	scanf("%s", str);
	reverse_str(str, strlen(str));
	printf("\nThe resultant string after reversal is: %s\n", str);
}