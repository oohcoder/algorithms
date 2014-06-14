/*
 * 插入排序算法
 * author: sean chen
 */
#include <stdio.h>
#include "lib/swapnum.h"
#include "lib/rangerand.h"
#include "lib/putarr.h"

#define SIZE 10

void insertion(int *arr, int size);


int main(void)
{
    int i;
    int arr[SIZE];
    rangeRand(0, 50, 10, arr);
    putarr(arr, SIZE);
    insertion(arr, SIZE);
    putarr(arr, SIZE);
    return 0;
}

void insertion(int *arr, int size)
{
    int i, j;
    for( i = 0; i < SIZE-1; i++) {
        for(j = i + 1; j > 0; j--) {
            if( arr[j] < arr[j-1]){
                swapNum(&arr[j], &arr[j-1]);
            } else {
                break;
            }
        }
    }
}




