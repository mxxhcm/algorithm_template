#include "sort.h"

/*
 *
 * 插入排序
 *
 */
void insert_sort(int a[], int n)
{
    int temp = -1;
    int i = - 1,j = -1;
    for(i = 1; i < n; i++)
    {
        temp = a[i];
        for(j = i-1; j >=0; j --)
        {
            if(temp < a[j])
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1] = temp;
    }
}
