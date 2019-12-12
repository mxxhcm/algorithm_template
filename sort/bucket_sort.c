#include <algorithm>
#include <vector>
#include "sort.h"

using std::vector;

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
