#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int N,M;
int d[1000010];

void solve()
{
    int ans = 0;
    static int qmax[1000010],qmin[1000010];
    int front1,front2,rear1,rear2;

    front1 = front2 = 0;
    rear1 = rear2 = 0;
    int i,j;
    for (i = 1,j = 1;j <= N;j++)
    {
        while (front1 < rear1 && d[qmax[rear1-1]] <= d[j]) rear1--;
        qmax[rear1++] = j;

        while (front2 < rear2 && d[qmin[rear2-1]] >= d[j]) rear2--;
        qmin[rear2++] = j;

        if (d[qmax[front1]] - d[qmin[front2]] > M)
        {
            ans = MAX(ans,j - i);
            while (d[qmax[front1]] - d[qmin[front2]] > M)
            {
                i = MIN(qmax[front1],qmin[front2]) + 1;
                while (front1 < rear1 && qmax[front1] < i) front1++;
                while (front2 < rear2 && qmin[front2] < i) front2++;
            }
        }
    }

    ans = MAX(ans,j - i);
    printf("%d\n",ans);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for (int i = 1;i <= N;i++)
            scanf("%d",&d[i]);

        solve();
    }

    return 0;
}
