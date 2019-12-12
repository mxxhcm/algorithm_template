#ifndef POINTER_ARRAY
#define POINTER_ARRAY

#include<stdio.h>
#include<stdlib.h>

// 1. sort
// sort array by first elements of array
void sort_pointer_array(int **array, int n);

// sort array
void sort_array(int *array, int n);

int cmp_pointer_array(const void *a, const void *b);

int cmp_array(const void *a, const void *b);

// 2. print
void print_array(int *array, int n);

void print_pointer_array(int **array, int n, int *size);

int *creat_array(int*n);

// 3. create
int** creat_pointer_array(int *n, int **size);

#endif
