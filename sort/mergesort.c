/*
 * 合并排序
 */
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "lib/swapnum.h"
#include "lib/rangerand.h"
#include "lib/putarr.h"
#define SIZE 10

void merge(int *arr,int low,int mid,int high);
void merge2(int *arr,int low,int mid,int high);
void mergeSort(int *arr, int low, int high);

int main()
{
    int arr[SIZE];
    rangeRand(0, 50, SIZE, arr);
    //int arr[SIZE] = {1, 3, 5, 7,  2, 4, 6, 8, 9, 10 };
    putarr(arr, SIZE);
    mergeSort(arr, 0, SIZE-1);
    //merge(arr, 0, 0, 0);
    putarr(arr, SIZE);
}

//递归调用，先对两边的数组排序，然后在合并
void mergeSort(int *arr, int low, int high) {
    if(low < high) {
        int mid = (int)(low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr,  mid + 1, high);
        merge2(arr, low, mid, high);

    }
}

//第一种合并方式
void merge(int *arr, int low, int mid, int high) {
    int *temp = malloc((high - low + 1)*sizeof(int));
    int m = low;
    int n = mid + 1;
    int k = 0;

    while(m <= mid && n <= high) {
        if(arr[m] <= arr[n]) {
            temp[k++] = arr[m++];
        } else {
            temp[k++] = arr[n++];
        }
    }

    if(m > mid) {
        while(n <= high) {
            temp[k++] = arr[n++];
        }
    }

    if(n > high) {
        while( m <= mid) {
            temp[k++] = arr[m++];
        }

    }
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
    free(temp);
}

//第二种合并方式
void merge2(int *arr, int low, int mid, int high) {
    int l1 = mid - low + 1;
    int l2 = high - mid;
    int i;
    int m = 0;
    int n = 0;
    int *temp1 = malloc((l1+1)*sizeof(int));
    int *temp2 = malloc((l2+1)*sizeof(int));

    for(i = 0; i < l1; i++) {
        temp1[i] = arr[low + i];
    }
    temp1[l1] = INT_MAX;
    for(i = 0; i < l2; i++) {
        temp2[i] = arr[mid+ i + 1];
    }
    temp2[l2] = INT_MAX;

    for(i = low; i <= high; i++){
        if(temp1[m] < temp2[n])
            arr[i] = temp1[m++];
        else
            arr[i] = temp2[n++];
    }

    free(temp1);
    free(temp2);

}
