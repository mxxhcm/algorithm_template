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
void print_array(const int *array, const int n);

void print_pointer_array(const int **array, const int n, const int *size);


// 3. create
// 创建一个整形数组，返回一个整形指针，ppi是一个整形指针的地址。
void creat_int_pointer(int **ppi, const int n);
// 创建一个字符数组，返回一个字符指针
void creat_char_pointer(char **ppc, const int n);

// 创建一个字符指针数组，返回一个指针的指针，ppca是一个指针的指针的地址
void creat_char_pointer_array(char ***ppca, const int n, const int *l);

#endif
