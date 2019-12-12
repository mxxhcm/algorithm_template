#include "sort.h"

/*
 *
 * 基数排序,需要使用到计数排序
 *
 *
 */
void radix_sort(int a[], int n)
{
    int max = get_max(a, n);
    printf("max=%d\n", max);
    for(int exp=1; max/exp > 0; exp*=10)
    {
        counting_sort(a, n, exp);
    }
}


int get_max(int a[], int n)
{
    int max = a[0];
    for(int i = 1; i < n ;i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}



