#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


#include "sort.h"


int main()
{

    //int a[100] = {29, 394, 56, 30, 340, 29, 49};
    //1. demo
    int a[] = {2, 3, 4, 5, 6, 1};
    int l = sizeof(a)/sizeof(int);
    insert_sort(a, l);
    for(int i = 0; i < l; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");

    // 2. test runtime

    const int N = 100000;
    int array[N] = {0};
    for(int i = 0; i < N; i++)
    {
        array[i] = rand();
        //printf("%d\n", array[i]);
    }

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    insert_sort(array, N);
     

    gettimeofday(&tv2, NULL);
    printf("run time: %f\n", (double)(tv2.tv_sec-tv1.tv_sec) + (double)(tv2.tv_usec - tv1.tv_usec)/1000000);

    //printf("after sort\n");
    for(int i = 0; i < N; i++)
    {
        break;
        //printf("%d\n", array[i]);
    }
    
    return 0;
}
