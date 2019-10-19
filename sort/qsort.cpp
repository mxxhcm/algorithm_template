#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<sys/time.h>

const int N = 10000;

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
    // 1. demo
    int array[] = {35, 39, 30, 40, 39, 20, 12};   
    int l = sizeof(array)/sizeof(int);

    quicksort(array, l);

    for(int i = 0; i < l; i ++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
 
    // 2. 1000000 random data
    int a[N] = {0};
    srand(time(NULL));  //初始化随机数

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    printf("============inputs ===============\n");
    for(int i = 0 ; i < N; i++)
    {
        a[i] = rand();
        //printf("%d\n", a[i]);
    }
    printf("============inputs end===============\n");

    quicksort(a, N);

    gettimeofday(&tv2, NULL);
    printf("%f\n", (double)(tv2.tv_sec-tv1.tv_sec + (double)(tv2.tv_usec-tv1.tv_usec)/1000000));
 
    printf("============outputs ===============\n");
    for(int i = 0 ; i < N; i++)
    {
        break;
        printf("%d\n", a[i]);
    }
    printf("============outputs end===============\n");

    return 0;
}
