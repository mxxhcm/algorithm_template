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
void creat_int_array(int **ppi, const int n);

// 创建一个字符数组，返回一个字符指针
void creat_char_array(char **ppc, const int n);

/*
 *
 * 创建一个字符指针数组，并且根据l为每个指针申请空间。
 *
 * ppca是一个字符指针数组的地址
 * 
 * n是一个整数
 * l是每个字符指针数组中每个指针指向的字符数组（字符串）的大小。
 *
 */
void creat_char_pointer_array(char ***ppca, const int n, const int *l);

/*
 * 
 * 创建一个字符指针数组，不为每个指针分配空间，也就说指针数组中每个指针都是无效指针。
 *
 */
void creat_char_pointer_array_without_allocation(char ***ppca, const int n);

#endif
