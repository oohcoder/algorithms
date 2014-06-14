#ifndef EXCHAGE_H
#define EXCHAGE_H
void swapNum(int *a, int *b);
#endif

void swapNum(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
