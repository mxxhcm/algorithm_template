#include "sort.h"


int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while(low < high)
    {
        while(low < high && a[high] >= pivot)
        {
            high --;
        }
        a[low] = a[high];
        while(low < high && a[low] <= pivot)
        {
            low ++;
        }
        a[high] = a[low];
    }
    a[low] =  pivot;
    return low;
}


int quicksort(int a[], int low, int high)
{
    if( low < high)
    {
        int pivot = partition(a, low, high);
        qsort(a, low,  pivot - 1);
        qsort(a, pivot + 1, high);
    }
}


void quick_sort(int a[], int n)
{
    qsort(a, 0, n-1);
}


