/*
 * 选择排序算法
 * author: sean chen
 */
#include <stdio.h>
#include "lib/swapnum.h"
#include "lib/rangerand.h"
#include "lib/putarr.h"

#define SIZE 10

void selection(int *arr, int size);

int main() {
    int i;
    int arr[SIZE];
    rangeRand(0, 50, 10, arr);
    putarr(arr, SIZE);
    selection(arr, SIZE);
    putarr(arr, SIZE);
    return 0;
}

void selection(int *arr, int size) {
    int i, j, min;
    for(i = 0; i < size; i++) {
        min = i;
        for(j = i; j < size; j++) {
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        if(min != i) {
            swapNum(&arr[i], &arr[min]);
        }
    }
}
