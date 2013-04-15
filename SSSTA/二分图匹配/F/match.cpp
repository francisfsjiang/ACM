#include<iostream>
#include<cstdio>
#include<string.h>
#define MAX 4000
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
    int x,y,t;
    while(1) 
    {
	scanf("%d%d",&n,&m);
	if(m==0&&n==0)break;
        memset(map,0,sizeof(map));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=true;
        }
        printf("%d\n",maxmatch());
    }
    return 0;
}
  
