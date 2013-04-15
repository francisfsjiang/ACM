#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char str[400];
    int n;
    while (~scanf("%d", &n))
    {
        scanf("%s", str);
        int t=n/2;
        for (int i=0; i<t; ++i)
        {
            if(str[i]=='R' && str[i+t]=='L')printf("%d %d\n", i+1+t, i+1);
            else printf("%d %d\n", i+1, i+t+1);
        }
    }
    return 0;
}
