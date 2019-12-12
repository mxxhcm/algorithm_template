#include <string.h>
#include <stdio.h>


int main()
{

    char str[] = "12, 43, 489, 29, 08";
    char delim[] = " ,";

    char *p = str, *res = NULL;

    printf("res=%s\n", res);
    printf("p=%s\n", p);

    while((res = strsep(&p, delim))!=NULL)
    {
        printf("res=%s\n", res);
        printf("p=%s\n", p);
    }

    return 0;

}
