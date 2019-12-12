#include "sort.h"
/*
 *
 * 堆排序
 * 简单写一下对排序的思路
 * 1. 首先建立一个最大堆,这个是最重要的一步,从最后一个非叶子节点进行heapify.一直到根节点.
 * 
 * 2. 建立最大堆之后,将根节点的最大元素和最后一个未排序节点交换,然后重新对根节点进行排序.循环下去直到全部有序
 *
 *
 *
 */

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && a[l] > a[largest])
    {
        largest = l;
    }

    if(r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if(i != largest)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest); 
    }
}

void build_max_heap(int a[], int n)
{
    for(int i = (n/2)- 1; i >= 0; --i)
    {
        heapify(a, n, i);
    } 
}

void heap_sort(int a[], int n)
{
    build_max_heap(a, n);

    for(int i = n-1; i > 0; --i)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

