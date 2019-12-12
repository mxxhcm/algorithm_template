#include<stdio.h>

/*
 *
 * 这个程序给出了c语言标准输入输出中字符，字符串的读写方式。
 *
 *
 */

int main()
{

    FILE* fp1 = fopen("str.txt", "r");
    if(fp1==NULL)
        return -1;

    printf("一、字符读写\n");
    printf("1. fgetc() and fputc() :\n");
    // getc() and putc()
    // fgetc() and fputc()
    int ch1 = 0;
    while((ch1 = fgetc(fp1)) != EOF)
    {
        fputc(ch1, stdout);
        printf("%d", ch1);
        fputc(44, stdout);
    }
    fclose(fp1);
    printf("=========================\n");

    FILE* fp2 = fopen("str.txt", "r");
    if(fp2==NULL)
        return -1;

    printf("\n2. getc() and putc() :\n");
    // getc() and putc()
    int ch2 = 0;
    while((ch2 = getc(fp2)) != EOF)
    {
        putc(ch2, stdout);
        putc(44, stdout);
    }
    fclose(fp2);
    printf("=========================\n");

 
    printf("\n二、读写n个字节\n");
    printf("\n3. fread() and fwrite(): \n");
    FILE* fp3 = fopen("str.txt", "r");
    if(fp3 == NULL)
        return -1;

    char buffer3[512] = "";
    while(!feof(fp3))
    {
        fread(buffer3, sizeof(int), 100, fp3);
        fwrite(buffer3, sizeof(int), 100, stdout);
    }
    fclose(fp3);
    printf("=========================\n");
    

    printf("\n三、读写字符串\n");
    printf("4. fgets() and fputs() : \n");
    FILE* fp4 = fopen("str.txt", "r");
    if(fp4 == NULL)
        return -1;

    // 定义一个字符数组或者字符传指针，字符串指针一定要手动分配内存空间，否则会出问题。
    char buffer4[512] = "";
    while(fgets(buffer4, sizeof(buffer4), fp4)!=NULL)
    {
        fputs(buffer4, stdout);
    }
    fclose(fp4);
    printf("=========================\n");
       

    printf("5. getline() : \n");
    FILE* fp5 = fopen("str.txt", "r");
    if(fp5 == NULL)
        return -1;

    char *buffer5 = NULL;
    size_t l = 512;
    while(getline(&buffer5, &l, fp5)!=EOF)
    {
        fputs(buffer5, stdout);
    }
    fclose(fp5);
    printf("=========================\n");


    printf("6. fscanf() and fprintf() : \n");
    FILE* fp6 = fopen("str.txt", "r");
    if(fp6 == NULL)
        return -1;

    char buffer6[512] = "";
    while(fscanf(fp6, "%s", buffer6)!=EOF)
    {
        printf("|");
        fprintf(stdout, "%s", buffer6);
    }
    printf("\n");
    fclose(fp6);
    printf("=========================\n");

    return 0;
}
