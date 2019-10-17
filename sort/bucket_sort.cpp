#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::vector;


int get_min(int a[], int n)
{
    int min = a[0];
    for(int i=1; i < n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int get_max(int a[], int n)
{
    int max = a[0];
    for(int i=1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}


void bucket_sort(int a[], int n, int bucket_number)
{
    // 1.创建n个桶
    std::vector<int> b[bucket_number];

    int max = get_max(a, n);
    int min = get_min(a, n);

    // 2.每个桶的大小
    int bucket_size = (max - min + 1) / bucket_number;
    for(int i = 0 ; i< n; i++)
    {
        int bucket_index = (a[i] - min) / bucket_size;
        b[bucket_index].push_back(a[i]);
    }

    for(int i = 0; i < bucket_number; i++)
    {
        sort(b[i].begin(), b[i].end());
    }
    int count = 0;
    for(int i = 0; i < bucket_number; i++)
    {
        for(int j = 0; j < b[i].size(); j++)
        {
            a[count++] = b[i][j];
        }
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
    int bucket_number = 5;
    bucket_sort(a, l, bucket_number);

    // 3.output
    printf("after sort: \n");
    for(int i = 0; i < l; i ++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
    return 0;
}

