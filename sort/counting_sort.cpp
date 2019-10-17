#include<cstdio>
#include<cstdlib>
#include<cstring>


void bucket_sort(int a[], int n, int k)
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


int main()
{
    int a[] = {2, 5, 3, 0, 2, 3, 0, 3};   
    int l = sizeof(a)/sizeof(int);
    bucket_sort(a, l, 41);
    for(int i = 0; i < l; i ++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
    return 0;
}

