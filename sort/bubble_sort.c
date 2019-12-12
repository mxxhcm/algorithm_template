#include <sort.h>

/*
 *
 * 冒泡排序
 *
 */
void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                flag = 1;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag==1)
            break;
    }
}
