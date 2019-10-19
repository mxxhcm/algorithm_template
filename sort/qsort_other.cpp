#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<sys/time.h>

const int N = 1000000;
// 10万,8.9
// 1万，0.13


// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

 

int main()
{
    // 1. demo
    int array[] = {35, 39, 30, 40, 39, 20, 12};   
    int l = sizeof(array)/sizeof(int);

    quickSort(array,0, l-1);

    for(int i = 0; i < l; i ++)
    {
        printf("%d,", array[i]);
    }
    printf("\n");
 
    // 2. 1000000 random data
    int a[N] = {0};
    srand(time(NULL));  //初始化随机数

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    printf("============inputs ===============\n");
    for(int i = 0 ; i < N; i++)
    {
        a[i] = rand();
        //printf("%d\n", a[i]);
    }
    printf("============inputs end===============\n");

    quickSort(a, 0, N-1);

    gettimeofday(&tv2, NULL);
    printf("%f\n", (double)(tv2.tv_sec-tv1.tv_sec + (double)(tv2.tv_usec-tv1.tv_usec)/1000000));
 
    printf("============outputs ===============\n");
    for(int i = 0 ; i < N; i++)
    {
        break;
        printf("%d\n", a[i]);
    }
    printf("============outputs end===============\n");

    return 0;
}

