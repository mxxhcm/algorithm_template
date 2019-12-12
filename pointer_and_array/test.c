#include "pointer_array.h"


int main(int argc, char *argv[])
{

    int n = 0;
    int *pa;
    pa = creat_array(&n);
    print_array(pa, n);

    n = 0;
    int *s;
    int **ppa = creat_pointer_array(&n, &s);

    print_pointer_array(ppa, n, s);
    
    return 0;
}
