#include <stdio.h> 
#include <stdlib.h>

int main() 
{ 
    char filename[20] = "data.txt";
    FILE *fp = fopen(filename, "r"); 
    if (fp == NULL) 
    { 
        printf("Cannot open file.\n"); 
        exit(0); 
    }
    else
    {
        printf("Open file %s success.\n", filename);
    }
    fclose(fp);

    return 0;
}
