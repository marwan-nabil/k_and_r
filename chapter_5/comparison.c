#include<stdio.h>
#include "generic_types.h"

int compare_ints(int x, int y)
{
	return x == y ? 0 : (x > y ? 1 : -1);
}

int compare_strings(char *x, char *y)
{
	int i=0;
	while(x[i]==y[i]){
		if(x[i]=='\0')
			return 0;
		i++;	
	}
	if(x[i] > y[i])
		return 1;
	else
		return -1;
}

