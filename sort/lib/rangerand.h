#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void rangeRand( int range_min, int range_max, int n , int *arr);

void rangeRand( int range_min, int range_max, int n , int *arr)
{
    int i;
    srand( (unsigned)time( NULL ) );
    for ( i = 0; i < n; i++ )
    {
        
        arr[i]  = rand()%(range_max-range_min) + range_min;
    }
}

