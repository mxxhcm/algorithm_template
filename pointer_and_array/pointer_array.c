#include "pointer_array.h"
#include <time.h> 


int cmp_array(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}


void sort_array(int *array, const int n)
{
    qsort(array, n, sizeof(int), cmp_array);
}


int cmp_pointer_array(const void *a, const void *b)
{
    return (**(int**)a - **(int**)b);
}


void sort_pointer_array(int **array, const int n)
{
    qsort(array, n, sizeof(int*), cmp_pointer_array);
}



void print_array(const int *array, const int n)
{
    
    for(const int *p = array; p != array+n; ++p)
    {
        printf("%d, ", *p);
    }
    printf("\n");
}

void print_pointer_array(const int **array, const int n, const int *size)
{
    for(const int **p = array; p!=array+n; ++p, ++size)
    {
        printf("size = %d:\n", *size);
        for(const int *temp = *p; temp != *p+*size; ++temp)
        {
            printf("%d,", *temp);
        }
        printf("\n");
    }
}

void creat_int_array(int **ppi, const int n)
{
    int *pi = (int*)realloc(*ppi, sizeof(int)*n);
    *ppi = pi;
}

void creat_char_array(char **ppc, const int n)
{
    char *pc = (char*)realloc(*ppc, sizeof(char)*n);
    *ppc = pc;
}


void creat_char_pointer_array(char ***ppca, const int n, const int *l)
{
    // realloc指针数组
    char **pca = (char**)realloc(*ppca, sizeof(char*) * n);

    // realloc指针数组中每个指针
    for(int i = 0; i < n; ++i)
    {
        creat_char_pointer(&pca[i], l[i]);
    }

    // 令*ppca指向新malloc的指针数组
    *ppca = pca;
}

void creat_char_pointer_array_without_allocation(char ***ppca, const int n);
{
    // realloc指针数组
    char **pca = (char**)realloc(*ppca, sizeof(char*) * n);

    // 令*ppca指向新malloc的指针数组，注意，并没有为指针数组中每个指针分配它指向的空间。
    *ppca = pca;
}


