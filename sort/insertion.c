#include <stdio.h>
#include "lib/exchange.h"

#define SIZE 10

void insertion(int *arr, int size);


int main(void)
{
    int i;
    int arr[SIZE] = {12, 23, 34, 45, 66, 2, 5,65, 23, 12};
    for(i = 0; i < SIZE; i++)
    {
        printf("arr[%d] = %d ", i, arr[i]);
    }
    putchar('\n');
    insertion(arr, SIZE);
    for(i = 0; i < SIZE; i++)
    {
        printf("arr[%d] = %d ", i, arr[i]);
    }
    putchar('\n');
    return 0;
}

void insertion(int *arr, int size)
{
    int i, j;
    for( i = 0; i < SIZE-1; i++) {
        for(j = i + 1; j > 0; j--) {
            if( arr[j] < arr[j-1]){
                exchange(&arr[j], &arr[j-1]);
            } else {
                break;
            }
        }
    }
}




