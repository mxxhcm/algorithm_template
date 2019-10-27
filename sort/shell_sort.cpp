#include<cstdio>
#include<cstdlib>
#include<ctime>


void shell_sort(int a[], int n)
{
    int i = -1, j = -1, temp = -1;
    for(int gap = n/2; gap > 0; gap/=2)
    {
        for(i = gap; i < n; i++)
        {
            temp = a[i];
            for(j = i - gap; j >= 0; j -= gap)
            {
                if(temp < a[j])
                {
                    a[j+gap] =  a[j];
                }
                else
                {
                    break;
                }
            }
            a[j+gap] = temp;
        }
    }
}


int main()
{

    // 1.demo
    int a[] = {29, 394, 56, 30, 340, 31, 49};
    int l = sizeof(a)/sizeof(int);

    shell_sort(a, l);

    for(int i = 0; i < l; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
    
    srand(time(NULL));

    //2.test run time
    const int N = 20;
    int array[N] = {0};
    for(int i = 0; i < N; i ++)
    {
        array[i] = rand();
        printf("%d\n", array[i]);
    }
    shell_sort(array, N);
    printf("after sort\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d\n", array[i]);
    }
}
