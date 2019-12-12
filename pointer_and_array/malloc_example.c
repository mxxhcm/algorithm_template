#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void creat_int_pointer(int **ppi, int n)
{
    int *pi = (int*)realloc(*ppi, sizeof(int)*n);
    *ppi = pi;
}

void creat_char_pointer(char **ppc, int n)
{
    char *pc = (char*)realloc(*ppc, sizeof(char)*n);
    *ppc = pc;
}


void creat_char_pointer_array(char ***ppca, int n, int *l)
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
