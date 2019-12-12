#include "sort.h"

void merge(int a[], int left, int middle, int right)
{
    int i = left, j = middle+1, count = 0;
    while((i <= middle) && (j <= right))
    {
        if(a[i] < a[j])
        {
            res[count++] = a[i++];
        }
        else
        {
            res[count++] = a[j++];
        }
    }

    // copy left
    while(i <= middle)
    {
        res[count++] = a[i++];
    }

    while(j <= right)
    {
        res[count++] = a[j++];
    }

    // copy to a
    i = 0;
    while(i < count)
    {
        a[left++] = res[i++];
    }

}


void mergesort(int a[], int l, int r)
{
    if(l < r)
    {
        //int middle = (l+r)/2 may be overflow, use (r-l)/2 + l 
        int m = (r-l)/2 + l;
        mergesort(a, l, m);
        mergesort(a, m+1, r);

        merge(a, l , m, r);
        //mergeData(a, l , m, r);
    }

}

void merge_sort(int a[], int n)
{
    mergesort(a, 0, n-1);
}


