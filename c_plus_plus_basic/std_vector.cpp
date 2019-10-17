#include<vector>
#include<cstdlib>
#include<cstdio>

using std::vector;

int main()
{

    int l = 3;
    std::vector<int> a[l];
    for(int i = 0 ; i < l; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            a[i].push_back(j);
        }
    }

    for(int i = 0 ; i < l; i++)
    {
        for(int j = 0; j < a[i].size(); j++)
        {
            printf("%d, ", a[i][j]);
        }
        printf("\n");
    }


}
