#include<iostream>
#include<cstdio>
#include<string.h>
#define MAX 400
using namespace std;
bool map[MAX][MAX];
int n,m,link[MAX];
bool vist[MAX];

bool find(int a)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(map[a][i]&&!vist[i])
        {
            vist[i]=1;
            if(link[i]==0||find(link[i]))
            {
                link[i]=a;
                return true;
            }
        }
    }
    return false;
}

int maxmatch()
{
    int i,sum=0;
    memset(link,0,sizeof(link));
    for (i=1;i<=n;i++)
    {
        memset(vist,false, sizeof(vist));
        if (find(i))sum++;
    }
    return sum;
}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i,b,c,t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b);
            while(b--)
            {
                scanf("%d",&c);
                map[i][c]=true;
            }
        }
        if(maxmatch()==n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
  
