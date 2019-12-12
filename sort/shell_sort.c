#include "sort.h"

/*
 *
 *
 * 希尔排序
 *
 */
void shell_sort(int a[], int n)
{
    int i = -1, j = -1, temp = -1;
    for(int gap = n/2; gap > 0; gap/=2)
    {
        for(i = gap; i < n; i++)
        {
            temp = a[i];
            for(j = i - gap; j >= 0; j -= gap)
            {
                if(temp < a[j])
                {
                    a[j+gap] =  a[j];
                }
                else
                {
                    break;
                }
            }
            a[j+gap] = temp;
        }
    }
}

