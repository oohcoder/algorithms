/*
 * 堆排序
 */
#include <stdio.h>
#include "lib/swapnum.h"
#include "lib/rangerand.h"
#include "lib/putarr.h"

#define SIZE 10

void heapSort(int *arr, int size);
void buildMaxHeap(int *arr, int size);
void maxHeap(int *arr, int size, int i);
int letfChilde(int i);
int rightChilde(int i);

int main(void)
{
    int i;
    int arr[SIZE];
    rangeRand(0, 50, 10, arr);
    putarr(arr, SIZE);
    heapSort(arr, SIZE);
    putarr(arr, SIZE);
    return 0;
}

void heapSort(int *arr, int size) 
{
    int i;
    buildMaxHeap(arr, size);
    for(i = size -1;  i >= 0; i--){
        swapNum(&arr[i], &arr[0]);
        buildMaxHeap(arr, i);
    }

}

void buildMaxHeap(int *arr, int size)
{
    int i, mid = size/2;
    for(i = mid; i >= 0; i--) {
        maxHeap(arr, size, i);
    }
}

void maxHeap(int *arr, int size, int i) {
    int max = i;
    int left = letfChilde(i);
    int right = rightChilde(i);
    if(left < size && arr[left] > arr[i]) {
        max = left;
    } 
    if( right < size && arr[right] > arr[max]) {
        max = right;
    }
    if(max != i) {
        swapNum(&arr[i], &arr[max]);
        maxHeap(arr, size, max);
    }
}

int letfChilde(int i) {
    return i<<1;
}

int rightChilde(int i) {
    return (i<<1) + 1;
}
