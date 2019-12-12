#include "sort.h"

void counting_sort(int a[], int n, int k)
{
    int output[n+1];
    int freq[k+1];
    memset(freq, 0, sizeof(freq));

    // freq[i] contains the number of elements equal to i
    for(int i = 0; i < n; i++)
    {
        freq[a[i]] ++;
    }
    
    // freq[i] contains the number of elements equal or less to i
    for(int i = 1; i <= k; i++)
    {
        freq[i] = freq[i] + freq[i-1];
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        output[freq[a[i]]--] = a[i];
    }
               
    for(int i = 0; i < n; i++)
    {
        a[i] = output[i+1];
    }
}


