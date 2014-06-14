#include <stdio.h>
#include "rangerand.h"

#define SIZE 10
int main()
{
    int arr[SIZE];
    int i;
    int num = 5;

    rangeRand(-5, 10, num, arr);
    for(i = 0; i< num; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

}
