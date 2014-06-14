/*
 * 插入排序的另一种写法
 */
#include <stdio.h>
#include "lib/rangerand.h"
#include "lib/swapnum.h"
#include "lib/putarr.h"

#define SIZE 14

void insertion(int *arr, int size);

int main()
{
    int arr[SIZE];
    rangeRand(0, 50, SIZE, arr);
    putarr(arr, SIZE);
    insertion(arr, SIZE);
    putarr(arr, SIZE);
    return 0;
}

void insertion(int *arr, int size) 
{
    int i, j, key;
    for(j = 1; j < size; j++) {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;

    }
}


