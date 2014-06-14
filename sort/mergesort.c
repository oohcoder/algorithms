/*
 * 合并排序
 */

#include <stdio.h>
#include "lib/swapnum.h"
#include "lib/rangerand.h"
#include "lib/putarr.h"
#define SIZE 10

void merge(int *arr, int start, int mid, int end);
//void mergesort(int arr, int size);

int main()
{
    //int arr[SIZE];
    //rangeRand(0, 50, SIZE, arr);
    int arr[SIZE] = {1, 3, 5, 7,  2, 4, 6, 8, 9, 10 };
    putarr(arr, SIZE);
    merge(arr, 0, 3, 9);
    putarr(arr, SIZE);
}

void merge(int *arr, int start, int mid, int end)
{
    int size1 = mid - start + 1; 
    int size2 = end - mid;
    int size = end - start + 1;
    int *arrtemp1 = malloc(size1*sizeof(int));
    int *arrtemp2 = malloc(size2*sizeof(int));
    int i, j, k;
    for(i = 0; i  < size1; i++) {
        arrtemp1[i] = arr[start + i];
    }
    for(i = 0; i  < size2; i++) {
        arrtemp2[i] = arr[mid + i + 1];
    }
    i = 0; 
    j = 0; 
    int l = 0; 
    int n = size1 > size2 ? size2 : size1;
    for(k = 0; k < n; k++) {
        if(arrtemp1[i] <= arrtemp2[j]) {
            arr[l++] = arrtemp1[i++];
        } else {
            arr[l++] = arrtemp2[j++];
        }
    }

    while( n < size1) {
            arr[l++] = arrtemp1[i++];
            n++;
    } 
    while( n < size2) {
            arr[l++] = arrtemp2[j++];
            n++;
    } 

    free(arrtemp1);
    free(arrtemp2);
}

