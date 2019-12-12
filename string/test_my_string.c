#include <string.h>
#include "my_string.h"


#define N 1000

void print_token_strtok(char *line, const char *delim);
void print_token_strsep(char *line, const char *delim);
int split_strsep(char ***res, int **lens, char *line, const char *delim, int remove_white_flag);
int split_strtok(char ***res, int **lens, char *line, const char *delim, int remove_white_flag);
void remove_white(char *line);


char str[] = "foo1 ,bar1 ,foo2 ,bar2 ,bar3 ,foo3";
char str2[] = "foo1 , , , , ,foo3";
char delim[] = " ,\t\f\r\v\n";

int main()
{
             
    printf("str=%s\n", str);
    int l = sizeof(str);

    // 1.
    char *p1 = (char*)malloc(l);
    printf("p1=%p\n", p1);
    strncpy(p1, str, l);
    print_token_strtok(p1, delim);
    printf("p1=%p\n", p1);
    free(p1);
    
    // 2.
    char *p2 = (char*)malloc(l);
    strncpy(p2, str, l);
    printf("%s\n", p2);
    remove_white(p2);
    printf("%s\n", p2);

    print_token_strsep(p2, delim);
    printf("p2=%p\n", p2);
    free(p2);

    // 3.
    char str_white[] = "   foo  , bar  ,   foo";
    printf("%s\n", str_white);
    remove_white(str_white);
    printf("%s\n", str_white);

   
    // 4.
    char *p4 = (char*)malloc(l);

    // 两个测试数据
    //strncpy(p4, str, l);
    strncpy(p4, str2, l);

    int *p4_lens = NULL;
    char **res4 = NULL;
    int n4 = split_strsep(&res4, &p4_lens, p4, ",", 1);
    for(int i = 0; i < n4; ++i)
    {
        printf("%s\n", res4[i]);
    }
    // free memory
    for(int i = 0; i < n4; ++i)
    {
        free(res4[i]);
    }
    free(res4);
    free(p4_lens);
    
    // 5.
    char *p5 = (char*)malloc(l);

    // 两个测试数据
    //strncpy(p5, str, l);
    strncpy(p5, str2, l);

    int *p5_lens = NULL;
    char **res5 = NULL;
    int n5 = split_strtok(&res5, &p5_lens, p5, ",", 1);
    printf("n5=%d\n", n5);

    for(int i = 0; i < n5; ++i)
    {
        printf("%s\n", res5[i]);
    }
    // free memory
    for(int i = 0; i < n5; ++i)
    {
        free(res5[i]);
    }
    free(res5);
    free(p5_lens);
 

    return 0;
}
