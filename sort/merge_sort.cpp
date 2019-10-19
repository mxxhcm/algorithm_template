#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<sys/time.h>

// 最大可以取到两百万
const int N = 10000;
int a[N] = {0};
// 100万，0.1秒左右
// 10万，0.02左右
// 1万，0.003左右


// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void mergeData(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        mergeData(arr, l, m, r); 
    } 
} 
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

void sort(int a[], int n)
{
    //merge_sort(a, 0, n-1);
    mergeSort(a, 0, n-1);
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
        break;
        printf("%d\n", a[i]);
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
