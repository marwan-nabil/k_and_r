#include<stdio.h>

int bin_search(int v[], int x, int n){
  int low,high,mid;
  low = 0;
  high = n-1;
  
  while(low < high){
    mid = (low+high)/2;

    if(x > v[mid])
      low = mid + 1;
    else
      high = mid ;     
  }

  if(x == v[high])
    return high;
  else
    return -1;
}

int main(void){
  int arr[10]={1,2,3,4,5,6,7,8,9,10};
  printf("\nFound 5 at index: %d\n", bin_search(arr, 5, 10));
}
