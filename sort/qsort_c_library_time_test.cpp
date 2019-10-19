#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<sys/time.h>
#include<algorithm>

using std::sort;

const int N = 1000000;
int a[N] = {0};

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main()
{
    // 1000000 random data
    srand(time(NULL));  //初始化随机数

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    // =================1.inputs==============
    printf("============inputs ===============\n");
    for(int i = 0 ; i < N; i++)
    {
        a[i] = rand();
        //printf("%d\n", a[i]);
    }
    printf("============inputs end===============\n");

    // =================2.sort=====================
    //qsort(a, N, sizeof(int), cmpfunc);
    std::sort(a, a+N);

    gettimeofday(&tv2, NULL);
    printf("%f\n", (double)(tv2.tv_sec-tv1.tv_sec + (double)(tv2.tv_usec-tv1.tv_usec)/1000000));
 
    // =================3.output=====================
    printf("============outputs ===============\n");
    for(int i = 0 ; i < N; i++)
    {
        break;
        printf("%d\n", a[i]);
    }
    printf("============outputs end===============\n");

    return 0;
}
