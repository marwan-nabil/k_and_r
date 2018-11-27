/* This program converts an integer value into a string of the same number */

#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 20

float itoa(int i, char *str)
{
	static unsigned int str_index = 0;
	if (i < 10){
		if (str_index < MAXSTR - 1){
			str[str_index++] = '0' + i;
			str[str_index] = '\0';
		}
		else {
			printf("\nError: internal buffer limit exceeded.\n");
			exit(1);
		}
	}
	else {
		if (str_index < MAXSTR - 1){
			itoa( i/10, str);
			str[str_index++] = '0' + i%10;
			str[str_index] = '\0';
		}
		else {
			printf("\nError: internal buffer limit exceeded.\n");
			exit(1);
		}
	}
}

int main()
{
	int i;
	char s[MAXSTR];
	printf("\nEnter a decimal number: ");
	scanf("%d", &i);
	itoa(i, s);
	printf("\nthe number as a string is: %s\n", s);
}
