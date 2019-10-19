#include<cstdio>
#include<cstdlib>


void merge(int a[], int l, int m, int r)
{
    int res[100] = { 0 };
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
    }

}


int main()
{
    int a[] = {35, 39, 30, 40, 39, 20,  12};   
    int l = sizeof(a)/sizeof(int);
    merge_sort(a, 0, l-1);
    for(int i = 0; i < l; i ++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
    return 0;
}
