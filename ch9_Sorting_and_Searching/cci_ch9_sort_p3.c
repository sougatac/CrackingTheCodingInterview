/*
 * Pivoted binary search.
 */

#include <stdio.h>


int findpivot(int* arr, int left, int right)
{
  int mid = 0;

  if (left<right)
   mid = (left+right)/2;
  else
    return -1;

  //if the mid is greater or lesser than it successer or predecessor
  if(arr[mid] > arr[mid+1])
    return mid;
  else if (arr[mid] < arr[mid-1])
    return mid-1;
  //if mid val > left val, left is sorted, search in right
  else if (arr[mid] > arr[left])
    findpivot(arr, mid+1, right);
  else
    findpivot(arr, left, mid-1);
}

void binarysearch(int* arr, int left, int right, int val)
{
  int mid;

  if (left<right)
    mid = (left+right)/2;
  else
  {
    printf("\n Value %d not found\n", val);
    return;
  }

  if(arr[mid] == val)
  {
    printf("\n Value %d is found in location %d \n", val, mid);
    return;
  }
  else if (val < arr[mid])
    binarysearch(arr, left, mid-1, val);
  else
    binarysearch(arr, mid+1, right, val);
}

int main()
{
  int arr[]={15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
  int pivot=0, num_elem;
  int val = 5;

  num_elem = sizeof(arr)/sizeof(arr[0]);
  pivot = findpivot(arr, 0, num_elem-1);
  printf("\n Pivot is at pos: %d \n", pivot);

  if(val > arr[0] && val <= arr[pivot])
    binarysearch(arr, 0, pivot, val);
  else
    binarysearch(arr, pivot+1, num_elem-1, val);
}
