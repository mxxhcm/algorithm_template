#include "my_string.h"

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

// use for split, create a dynamic array
void creat_char_pointer_array_without_allocation(char ***ppc, int size)
{
    char **res = (char**)realloc(*ppc, sizeof(char*) *size);
    *ppc = res;
}

// use for splite, create a dynamic array
void creat_int_array(int **ppi, int sz)
{
    int *pi = (int*)realloc(*ppi, sizeof(int)*sz);
    *ppi = pi;
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

