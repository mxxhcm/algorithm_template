#include<cstdio>
#include<cstdlib>


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


int qsort(int a[], int low, int high)
{
    if( low < high)
    {
        int pivot = partition(a, low, high);
        qsort(a, low,  pivot - 1);
        qsort(a, pivot + 1, high);
    }
}


void quicksort(int a[], int n)
{
    qsort(a, 0, n-1);
}

int main()
{
    int a[100] = {35, 39, 30, 40, 39, 20, 12};   
    int l = 7;
    quicksort(a, l);
    for(int i = 0; i < l; i ++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
    return 0;
}
