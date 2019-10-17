#include<cstdio>
#include<cstdlib>


void insert_sort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        
        int temp = a[i];
        for(int j = i - 1; j >= 0; j--)
        {
            if(a[j] > temp)
            {
                a[j+1] = a[j];
            }
            else 
            {
                a[j+1] = temp;
                break;
            }
        }
    }
}


int main()
{

    int a[100] = {29, 394, 56, 30, 340, 29, 49};
    int l = 4;
    insert_sort(a, 4);
    for(int i = 0; i < 4; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
    
}
