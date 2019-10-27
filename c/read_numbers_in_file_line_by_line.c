#include <stdio.h> 
#include <stdlib.h>

#define N 510

int main() 
{ 
	char filename[20] = "data.txt";
	FILE *fp = fopen(filename, "r"); 
	if (fp == NULL) 
	{ 
		printf("Cannot open file \n"); 
		exit(0); 
	} 

    char chunk[128];
    int array[N] = {0};
    int count = 0;
	while (fgets(chunk, sizeof(chunk), fp)!=NULL) 
	{ 
        array[count] = atoi(chunk);
        count += 1;
	} 
	fclose(fp); 

	return 0; 
}

