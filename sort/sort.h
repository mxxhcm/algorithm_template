#include <stdio.h>
#include <stdlib.h>

// array
//const int N = 100000000;
#define N 10000000
int a[N] = {0};
int res[N] = { 0 };

// tools
void print_array(int a[], int n);
void swap(int *a, int *b);
int get_max(int a[], int n);
int get_min(int a[], int n);

// 1. bubble sort
void bubble_sort(int a[], int n);

// 2. insert sort
void insert_sort(int a[], int n);

// 3. selection sort
void selection_sort(int a[], int n);

// 4. heap sort
void heap_sort(int a[], int n);
void build_max_heap(int a[], int n);
void heapify(int a[], int n, int i);

// 5. shell sort
void shell_sort(int a[], int n);

// 6. quick sort
void quick_sort(int a[], int n);
int partition(int a[], int low, int high);
int quicksort(int a[], int low, int high);

// 7. merge sort
void merge_sort(int a[], int l, int r);
void mergesort(int a[], int n);
void merge(int a[], int left, int middle, int right);

// 8. counting_sort
void counting_sort(int a[], int n, int k);

// 9. radix sort
void radix_sort(int a[], int n);

// 10. bucket sort
void bucket_sort(int a[], int n, int bucket_number);


