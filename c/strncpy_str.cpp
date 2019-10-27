#include <cstring>
#include <cstdlib>
#include <cstdio>

int main()
{
    char str1[20] = "hello world", str2[20] = "";
    strncpy(str2, str1+ 3, 4);
    printf("%s\n", str2);
}
