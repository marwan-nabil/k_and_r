#include<stdio.h>
#include "generic_types.h"

#if 0
void test_one_swap(void){
	printf("\nbuilding the array {1,2,3,4,5,6,7,8,9}\n");
	T array[] = {1,2,3,4,5,6,7,8,9};
	printf("swapping the 4th and 7th elements\n");
	swap(&array, 4, 7);
	printf("printing the resulting array:\n");
	for (int i = 0; i<= 8; i++){
		printf("%d ",array[i]);
	}
	printf("\nTest 1 finished\n");
}

void test_two_swap(void){
	printf("\nbuilding the array {\"foo\", \"bar\", \"baz\", \"the knights who say ni\"}\n");
	T array[] = {"foo", "bar", "baz", "the knights who say ni"};
	printf("swapping the 0th and 3rd elements\n");
	swap(&array, 0, 3);
	printf("printing the resulting array:\n");
	for (int i = 0; i<= 3; i++){
		printf("%s ", array[i]);
	}
	printf("\nTest 2 finished\n");
}
#endif
void test_three_compare_strings(void){
	printf("\ncomparing foo and bar returns: %d", compare_strings("foo", "bar"));
	printf("\ncomparing foo and foo returns: %d", compare_strings("foo", "foo"));
	printf("\ncomparing foo and \"\" returns: %d", compare_strings("foo", ""));
	printf("\ncomparing foo and Foo returns: %d", compare_strings("foo", "Foo"));
	printf("\ncomparing foo and fooOo returns: %d", compare_strings("foo", "fooOo"));
	printf("\nTest 3 finished\n");
}
