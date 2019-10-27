#include <vector>
#include <cstdio>
#include <cstdlib>

using std::vector;

int main()
{
    
    // 1. size 为1，默认值为2的vector
    vector<int> a{1, 2};
    for(int i = 0; i < a.size(); i++)
    {
        printf("%d\n", a[i]);
    }

    // 2.数组初始化vector
    int e = {1, 2, 3};
    vector<int> f(e, e+3);
    for( int i =0 ;i < e.sizef(); i++)
    {
        printf("%d\n", e[i]);
    }

    return 0;
}
