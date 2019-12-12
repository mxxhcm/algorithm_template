#include <string.h>
#include "split.h"


#define N 1000

void print_token_strtok(char *line, const char *delim);
void print_token_strsep(char *line, const char *delim);
void split_strtok(char *str, const char *delim, char ***res); 
void split_strsep(char *str, const char *delim, char ***res);
void remove_duplicate_white(char *line);


char str[] = "foo1 ,bar1 ,foo2 ,bar2 ,bar3 ,foo3";
char delim[] = " ,\t\f\r\v\n";

int main()
{
             
    printf("str=%s\n", str);
    int l = sizeof(str)/sizeof(char);

    //
    char *p1 = (char*)malloc(sizeof(char)*l);
    printf("p1=%p\n", p1);
    strncpy(p1, str, l);
    print_token_strtok(p1, delim);
    printf("p1=%p\n", p1);
    
    //
    char *p2 = (char*)malloc(sizeof(char)*l);
    strncpy(p2, str, l);
    printf("%s\n", p2);
    print_token_strsep(p2, delim);
    printf("p2=%p\n", p2);
    free(p1);
    free(p2);

    char str_white[] = "   foo  , bar  ,   foo";
    remove_duplicate_white(str_white);
    printf("%s\n", str_white);
    
    return 0;
}
