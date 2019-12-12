
#include "sort.h"


void print_array(int a[], int n)
{
    for(int i = 0; i < n ; ++i)
    {
        printf("%d\n", a[i]);
    }
}

void swap(int *a, int *b)
{

    int temp  = *a;
    *a = *b;
    *b = temp;
}

int get_min(int a[], int n)
{
    int min = a[0];
    for(int i=1; i < n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int get_max(int a[], int n)
{
    int max = a[0];
    for(int i=1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
