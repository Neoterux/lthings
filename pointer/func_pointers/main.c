#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/**
 *  Defining an int function that receive nothing 
 *  as a.
 */
typedef int (*a)(int);


int test_func(int test){
  return 1 + test;
}

void test_arr(int *arr, size_t len, a modifier);

int print_arr(int *arr, size_t len);

int main (void)
{
  a test = test_func;
  int t_arr[20];
  size_t len = sizeof(t_arr)/sizeof(t_arr[0]);
  printf("size of array : %lu\n", len);
  int pos = 0;
  for(int *pointer = t_arr; pos < len; pos++)
    *(pointer++) = pos;
  
  print_arr(t_arr, len);
  
  test_arr(t_arr, len, test);
  
  printf("\nAfter modifing... \n");

  printf("processed = %d", print_arr(t_arr, len));
}

void test_arr(int *arr, size_t len, a modifier){
  for (int i = 0; i < len; i++) {
    int curr = *arr;
    *(arr++) = modifier(rand()%24 + curr);
  }
}

int print_arr(int *arr, size_t len){
  size_t i;
  printf("[");
  for (i = 0; i < len; i++){
    printf("%d", arr[i]);
    if (i < len-1)
      printf(", ");
  }
  printf("]\n");

  return i;

}
