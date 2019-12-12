#include "pointer_array.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char str[] = "hello world";
char *pc_array[] = {"mxxhcm", "hi", "mhhhpl", "sad"};

int main()
{
    int n = 2;
    int l1 = sizeof(str)/sizeof(char);
    while(n < l1)
    {
        n = n *2;
    }

    char *p = NULL;
    creat_char_pointer(&p, n);
    strncpy(p, str, l1);

    printf("%s\n", p);


    int l2 = sizeof(pc_array)/sizeof(char*);
    while(n < l2)
    {
        n = n*2;
    }

    char **ppc = NULL;
    int *pi = NULL;
    creat_int_pointer(&pi, l2);
    for(int i = 0; i < l2; ++i)
    {
        int len = 0;
        while(pc_array[i][len] != '\0')
        {
            len ++;
        }
        len ++;
        pi[i] = len;    //存放'\0'
        printf("%d\n", pi[i]);
        
    }

    creat_char_pointer_array(&ppc, n, pi);

    for(int i = 0; i < l2; ++i)
    {
        strncpy(ppc[i], pc_array[i], pi[i]);
        printf("%s\n", ppc[i]);
    }

    return 0;

}

