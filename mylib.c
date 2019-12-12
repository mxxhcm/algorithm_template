#include "mylib.h"


//================================begin my string.c=========================
void print_token_strtok(char *line, const char *delim)
{
    char *token = strtok(line, delim);
    printf("first token is: %s\n", token);
    while((token = strtok(NULL, delim))!=NULL)
    {
        printf("Next token is %s\n", token);
    }

}

void print_token_strsep(char *line, const char *delim)
{
    char *token;
    while((token = strsep(&line, delim)) !=NULL)
    {
        printf("token is '%s'\n", token);
    }
    
}

// return char *res[],
int split_strtok(char ***res, int **lens, char *line, const char *delim, int remove_white_flag)
{

    if(remove_white_flag)
        remove_white(line);

    int capacity = 16;
    creat_char_pointer_array_without_allocation(res, capacity);
    creat_int_array(lens, capacity);

    int count = 0;
    char *token, *p;

    // first token
    token = strtok(line, delim); 

    p = (char*)malloc(sizeof(char)*sizeof(token));
    strncpy(p, token, sizeof(token));

    count ++;
    (*res)[count-1] = p;
    (*lens)[count-1] = sizeof(token)/sizeof(char);

    // next token
    while((token = strtok(NULL, delim)) != NULL)
    {
        count ++;
        if(count >= capacity)
        {
            printf("realloc\n");
            capacity *= 2;
            while(count >= capacity)
            {
                creat_char_pointer_array_without_allocation(res, capacity);
                creat_int_array(lens, capacity);
            }

        }

        p = (char*)malloc(sizeof(char)*sizeof(token));
        strncpy(p, token, sizeof(token));
        
        (*res)[count-1] = p;
        (*lens)[count-1] = sizeof(token)/sizeof(char);
    }

    return count;

}


int split_strsep(char ***res, int **lens, char *line, const char *delim, int remove_white_flag)
{
    // 移除空格
    if(remove_white_flag != 0)
        remove_white(line);
    
    char *token, *p;
    int capacity = 16, count = 0;

    int l;

    creat_char_pointer_array_without_allocation(res, capacity);
    creat_int_array(lens, capacity);

    while((token = strsep(&line, delim)) != NULL)
    {
        //为返回的字符指针数组指向的字符串分配空间
        count ++;
        if(count >= capacity)
        {
            printf("realloc\n");
            capacity *= 2; 

            while(count >= capacity)
            {
                capacity = capacity*2; 
            }
            creat_char_pointer_array_without_allocation(res, capacity);
            creat_int_array(lens, capacity);
        }

        l = sizeof(token)/sizeof(char);
        p = (char*)malloc(l*sizeof(char));
        strncpy(p, token, sizeof(char)*l);

        //*res 是指针的指针
        (*res)[count-1] = p;
        (*lens)[count-1] = l;
        
    }

    return count;

}

void remove_white(char *line)
{
    int n = strlen(line);
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        if(line[i] != ' ')
            line[count++] = line[i];
    } 
    line[count] = '\0';
}
//================================end my string.c==========================
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

void creat_int_pointer(int **ppi, const int n)
{
    int *pi = (int*)realloc(*ppi, sizeof(int)*n);
    *ppi = pi;
}

void creat_char_pointer(char **ppc, const int n)
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
