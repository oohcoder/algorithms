#include <stdio.h>
void putarr(int *arr, int n);

void putarr(int *arr, int n) {
    int i;
    puts("-----------------start....-------------------\n");
    for(i = 0; i < n ; i++) {
        printf("\tarr[%d] = %10d\n", i, arr[i]); 
    }
    putchar('\n');
    puts("******************end...********************\n");
}
