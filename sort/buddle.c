#include <stdio.h>
#include "lib/exchange.h"
#include "lib/draw.h"
#include "lib/common.h"

#define SIZE 10
void buddle(int *arr, int size);

int main()
{
    int i;
    int arr[SIZE] = {};
    srand(time(NULL));
    for(i = 0; i  < SIZE; i++)
    {
        arr[i] = 10 + rand()% 20;
    }
    for(i = 0; i  < SIZE; i++)
    {
        mvprintw(5, 5, "%d\t", arr[i]);
    }
    initDraw();
    buddle(arr, SIZE);
    endDraw();
    putchar('\n');
    return 0;
}


void buddle(int *arr, int size)
{
    int i, j;
    for(i = 0; i <  size; i++){
        for(j = size - 1; j > i; j--) {
            if(arr[j] < arr[j-1]) {
                exchange(&arr[j], &arr[j-1]);
                doDraw(arr, size, j);
            }
            sleep(1000000);
        }
    }
}
