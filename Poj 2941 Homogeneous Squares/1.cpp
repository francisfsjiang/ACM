#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 1005

int n;
int map[maxn][maxn];

void input()
{
    for (int i =0; i < n; i++)
        for (int j =0; j < n; j++)
            scanf("%d", &map[i][j]);
}

bool ok()
{
    for (int i =1; i < n; i++)
    {
        int x = map[i][0] - map[i -1][0];
        for (int j =0; j < n; j++)
            if (map[i][j] - map[i -1][j] != x)
                return false;
    }
    return true;
}

int main()
{
    //freopen("t.txt", "r", stdin);
	while (scanf("%d", &n), n)
    {
        input();
        if (ok())
            printf("homogeneous\n");
        else
            printf("not homogeneous\n");
    }
    return 0;
}
