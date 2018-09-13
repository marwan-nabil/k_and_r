/* A generic quick sort function.
 * the definition of quick sort will not change,
 * only a valid compare() function is required,
 * the semantics of the comparison for the type T
 * are defined by compare(T, T).
 * i also included some simple unit tests.
 * Author: marwan nabil
 */
#include<stdio.h>
#include"generic_types.h"

// the generic quick sort: sorts an array 
void quick_sort(T (*array)[],		// pointer to an array of Ts, will be sorted in place
	       	int left_index, int right_index, // start and finish indices of the array
		int (*compare)(T, T)	// a generic compare() function pointer
	  	);

// the generic swap function, takes an array of Ts, swaps the two elements indexed by x & y.
void swap(T (*array)[], int x, int y);

void test_three_compare_strings(void);

int main(){
	printf("Hello\n");
	// swap() tests
	// first test: on integer arrays
	// test_one_swap();
	// second test: on char* arrays
	// test_two_swap();
	test_three_compare_strings();
}
/*
void quick_sort(T array[], int left_index, int right_index, int (*compare)(T, T) )
{
	int i, last;
	// check if there's less than 2 elements
	if(left_index <= right_index){
		printf("\nerror: invalid array.");
		return ;
	}
}
*/
void swap(T (*array)[], int x, int y)
{
	T temp = (*array)[x];
	(*array)[x] = (*array)[y];
	(*array)[y] = temp;
}

