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

void split_strtok(char *line, const char *delim, char ***res)
{


}


void split_strsep(char *line, const char *delim, char ***res)
{

}

void remove_duplicate_white(char *line)
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

