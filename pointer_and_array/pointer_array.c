#include "pointer_array.h"
#include <time.h> 

#define ARRAY_SIZE 10
#define ARRAY_NUM 10

void sort_pointer_array(int **array, int n)
{
    qsort(array, n, sizeof(int*), cmp_pointer_array);
}


void sort_array(int *array, int n)
{
    qsort(array, n, sizeof(int), cmp_array);
}


int cmp_pointer_array(const void *a, const void *b)
{
    return (**(int**)a - **(int**)b);
}


int cmp_array(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}


void print_array(int *array, int n)
{
    
    for(int *p = array; p != array+n; ++p)
    {
        printf("%d, ", *p);
    }
    printf("\n");
}

void print_pointer_array(int **array, int n, int *size)
{
    for(int **p = array; p!=array+n; ++p, ++size)
    {
        printf("size = %d:\n", *size);
        for(int *temp = *p; temp != *p+*size; ++temp)
        {
            printf("%d,", *temp);
        }
        printf("\n");
    }
}

int** creat_pointer_array(int *n, int **size)
{
    if(*n == 0)
    {
        *n = ARRAY_NUM;
    }
    int **array = (int**)malloc((*n) *sizeof(int*));
    
    // size是一个指向int的指针的指针
    // *size 是一个指向int的指针
    *size = (int*)malloc(sizeof(int)*10);
    //int *array[n];
    
    int count = 0;
    int *s = *size;
    for(int **ppi = array; ppi!= array+*n; ++ppi, ++s)
    {
        *s = ARRAY_SIZE;
        *ppi = (int*)malloc(ARRAY_SIZE *sizeof(int));
        for(int *temp = *ppi; temp!= *ppi+*s; ++temp)
        {
            *temp = ++count;
        }
    }
 
    return array;
}

int *creat_array(int *n)
{
    if(*n == 0)
    {
        *n = ARRAY_SIZE;
    }

    int seed = 0;
    srand(seed);

    int *array = (int *)malloc((*n)*sizeof(int));
    int count = 0;

    for(int *pa = array; pa !=array+*n; ++pa)
    {
        *pa = rand() % 100;
    }

    return array;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){

    if(intervalsSize == 0)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
        
    // sort pointer array
    qsort(intervals, intervalsSize, sizeof(int*), cmp_pointer_array);
    
    *returnSize = intervalsSize;    // size of return array 
    *returnColumnSizes = (int*)malloc(*returnSize*sizeof(int)); // size list of pointer array
    int **array = (int**)malloc(intervalsSize * sizeof(int*));    // pointer array
    
    int count = 0;
    int interval_l = 2;
    int *temp;
    temp = (int*)malloc(sizeof(int)*interval_l);   
    *(*returnColumnSizes+count) = 2;
    array[count++] = temp;
    *temp = *(*intervals);  // temp is a pointer to int
    *(temp+1) = *(*intervals+1);    // temp+1 is a pointer to int
    
    int last_end = temp[1];
    
    for(int i = 1 ; i < intervalsSize; ++i)
    {
        int begin = intervals[i][0];
        int end = intervals[i][1];
        if(begin > last_end)
        {
            temp = (int*)malloc(sizeof(int)*interval_l);
            *(*returnColumnSizes+count) = 2;
            array[count]  = temp;
            array[count][0] = begin;
            array[count++][1] = end;
            
            last_end = end;
        }
        else
        {
            if(end > last_end)
            {    
                array[count-1][1] =  end;
                
                last_end = end;
            }
            
        }
    }
        
    *returnSize = count;
    return array;
}

