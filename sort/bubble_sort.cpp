#include<cstdio>
#include<cstdlib>


void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                flag = true;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(!flag)
            break;
    }
}


int main()
{
    int a[100] = {12, 30, 40, 39, 20, 39};   
    int l = 6;
    bubble_sort(a, l);
    for(int i = 0; i < l; i ++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
    return 0;
}
