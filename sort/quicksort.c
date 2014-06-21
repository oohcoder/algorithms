/*
 * 快速排序
 */
#include <stdio.h>
#include "lib/swapnum.h"
#include "lib/rangerand.h"
#include "lib/putarr.h"

#define SIZE 10

void heapSort(int *arr, int size);
void buildMaxHeap(int *arr, int size);
void quickSort(int *arr, int low, int high);
int quick(int *arr, int low, int high);

int main(void)
{
    int i;
    int arr[SIZE];
    rangeRand(0, 50, 10, arr);
    putarr(arr, SIZE);
    quickSort(arr, 0, SIZE - 1);
    putarr(arr, SIZE);
    return 0;
}

void quickSort(int *arr, int low, int high) {
  int i;
  if(low < high) {
   i = quick(arr, low, high);
   quickSort(arr, low, i - 1);
   quickSort(arr, i+1, high); 
  }
}

int quick(int *arr, int low, int high) {
    int mid = (low + high)/2;
    int temp = arr[mid];
    swapNum(&arr[mid], &arr[high]);
    int i , j;
    i = low;
    j = low;
    while(i < high  ) {
        if(arr[i] <= temp) {
            swapNum(&arr[i], &arr[j]);
            j++;
        }
        i++;
    }
    swapNum(&arr[high], &arr[j]);
    return j;
}
