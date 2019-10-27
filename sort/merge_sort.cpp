#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<sys/time.h>

// 最大可以取到两百万
const int N = 1000000;
int a[N] = {0};
// 100万，0.2秒左右
// 10万，0.02左右
// 1万，0.004左右

void merge(int a[], int l, int m, int r)
{
    //注意！！！不用声明N的临时数组即可。
    //int res[N] = { 0 };
    int res[r-l+1] = { 0 };
    int i = l, j = m+1, k = 0;
    // merge
    while((i <= m) && (j <= r))
    {
        if(a[i] < a[j])
        {
            res[k++] = a[i++];
        }
        else
        {
            res[k++] = a[j++];
        }
    }

    // copy left
    for( ; i <= m; )
    {
        res[k++] = a[i++];
    }

    for( ; j <= r; )
    {
        res[k++] = a[j++];
    }

    // copy to a
    for(int t = l; t <=r; t++)
    {
        a[t] = res[t-l];
    }
}


void merge_sort(int a[], int l, int r)
{
    if(l < r)
    {
        //int middle = (l+r)/2 may be overflow, use (r-l)/2 + l 
        int m = (r-l)/2 + l;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l , m, r);
        //mergeData(a, l , m, r);
    }

}

void sort(int a[], int n)
{
    merge_sort(a, 0, n-1);
}

int main()
{
    // 1. demo
    int array[] = {35, 39, 30, 40, 39, 20, 12};   
    int l = sizeof(array)/sizeof(int);

    sort(array, l);

    for(int i = 0; i < l; i ++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
 
    // 2. 1000000 random data
    srand(time(NULL));  //初始化随机数

    // =================1. input ===============
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    printf("============inputs ===============\n");
    for(int i = 0 ; i < N; i++)
    {
        a[i] = rand();
        //printf("%d\n", a[i]);
    }
    printf("============inputs end===============\n");


    // =================2. sort===============
    sort(a, N);

    gettimeofday(&tv2, NULL);
    printf("%f\n", (double)(tv2.tv_sec-tv1.tv_sec + (double)(tv2.tv_usec-tv1.tv_usec)/1000000));
 
    // =================3. output===============
    printf("============outputs ===============\n");
    for(int i = 0 ; i < N; i++)
    {
        break;
        printf("%d\n", a[i]);
    }
    printf("============outputs end===============\n");

    return 0;

}
