/*
 * You are given 2 sorted arrays A and B, and A has large enough buffer
 * at the end to hold B. Write a method to merge B into A in a sorted order.
 */

#include <stdio.h>

void merge(int* A, int* B, int num_a, int num_b)
{
  int num_elem = num_a + num_b;
  int idx = num_elem -1;
  int a_pos = num_a - 1;
  int b_pos = num_b - 1;

  while(b_pos>=0)
  {
    if(A[a_pos] > B[b_pos])
    {
      A[idx] = A[a_pos];
      idx--;
      a_pos--;
    }
    else
    {
      A[idx] = B[b_pos];
      b_pos--;
      idx--;
    }
  }

  printf("\nPrinting final array\n");
  for(idx=0; idx<num_elem; idx++)
    printf(" \t %d", A[idx]);

  printf("\n");
}

int main()
{

  int A[100] = {1,3,5,7,8,10,12,13,15,17,19};
  int B[5] = {2, 9, 11, 20, 23};
  int num_a = 11;
  int num_b = 5;

  merge(A, B, num_a, num_b);
}
