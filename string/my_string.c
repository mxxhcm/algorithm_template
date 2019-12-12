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

// return char *res[],
void split_strtok(char *line, const char *delim, char ***res)
{
    char *token = strtok(line, delim); 
    printf("token: %s\n", token);

    while((token = strtok(NULL, delim) != NULL))
    {
        printf("token: %s\n", token);
    }

}

void create_char_pointer_array(char **ppc, int size)
{
    char **res = (char**)realloc(ppc, sizeof(char*) *size);
    return res;
}

void split_strsep(char *line, const char *delim, char ***res, int *n, int remove_white)
{
    if(*res == NULL)
    {
        *n = 16;
        create_char_pointer_array(*res, *n); 
    }

    if(remove_white != 0)
        remove_white(line);
    char *token;
    int count = 0;
    while((token = strsep(line, delim)) != NULL)
    {
        printf("%s\n", token);
        char *p = (char*)malloc(sizeof(token));
        count ++;
        if(count >= *n)
        {
            *n = *n*2; 
            create_char_pointer_array(*res, *n); 
        }
        *res[]
    }

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

