
/*
 * 冒泡排序法 
 * author: sean chen
 */
#include <stdio.h>
#include "lib/swapnum.h"
#include "lib/rangerand.h"
#include "lib/putarr.h"

#define SIZE 10

void bubble(int *arr, int size);

int main()
{
    int i;
    int arr[SIZE];
    rangeRand(0, 50, 10, arr);
    putarr(arr, SIZE);
    bubble(arr, SIZE);
    putarr(arr, SIZE);
    return 0;
}


void bubble(int *arr, int size)
{
    int i, j;
    for(i = 0; i <  size; i++){
        for(j = size - 1; j > i; j--) {
            if(arr[j] < arr[j-1]) {
                swapNum(&arr[j], &arr[j-1]);
            }
        }
    }
}
