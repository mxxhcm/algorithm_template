#include "sort.h"

/*
 *
 *
 * 选择排序
 *
 */
void selection_sort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for(int j = i; j < n; j++)
        {
            if(a[j] < a[min_index]) 
                min_index = j;
        }
        if(min_index != i)
        {
            int temp = a[min_index];
            a[min_index] = a[i];
            a[i] = temp;
        }
    }
}

