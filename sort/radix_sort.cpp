#include<cstdio>
#include<cstdlib>
#include<cstring>


int get_max(int a[], int n)
{
    int max = a[0];
    for(int i = 1; i < n ;i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}


void counting_sort(int a[], int n, int exp)
{
    int count[10];
    int output[n+1];
    memset(count, 0, sizeof(count));

    //329, 457, 657, 839, 436, 726, 255
    // 1.count
    for(int i = 0; i < n; i ++)
    {
        int temp = (a[i] / exp) % 10;
        count[temp] ++;
    }

    // 2.accumulate count
    for(int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    // 3.sort
    for(int i = n - 1; i >= 0; i--)
    {
        int temp = (a[i] / exp) % 10;
        output[count[temp]--] = a[i];
    }

    // 4. copy
    for(int i = 0; i < n; i++)
    {
        a[i] = output[i+1];
        printf("%d, ", a[i]);
    }
    printf("\n");
}


void bucket_sort(int a[], int n)
{
    int max = get_max(a, n);
    printf("max=%d\n", max);
    for(int exp=1; max/exp > 0; exp*=10)
    {
        counting_sort(a, n, exp);
    }
}


int main()
{
    int a[] = {329, 457, 657, 839, 436, 726, 255};
    int l = sizeof(a)/sizeof(int);
    // 1.input
    for(int i = 0; i < l; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");

    // 2.sort
    bucket_sort(a, l);

    // 3.output
    printf("after sort: \n");
    for(int i = 0; i < l; i ++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
    return 0;
}

