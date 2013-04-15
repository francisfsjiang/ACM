#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x7fffffff;
int n,p,k;
int map[1005][1005];
int dis[1005];
bool tag[1005];
struct node
{
    int a,b,w;
};
node edge[10010];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
void inite(int key)                       //构造新的图
{
    int i,j;
    int a,b;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i!=j)
            {
                map[i][j]=INF;
            }
            else
            {
                map[i][j]=0;
            }
        }
    }
    for(i=0; i<p; i++)
    {
        a=edge[i].a;
        b=edge[i].b;
        if(edge[i].w>key)
        {
            map[a][b]=map[b][a]=1;
        }
        else
        {
            map[a][b]=map[b][a]=0;
        }
    }
}

int djk()
{
    int i,j,min,local;
    int ndis;
    for(i=1; i<=n; i++)
    {
        dis[i]=map[1][i];
        tag[i]=false;
    }
    tag[1]=true;
    for(i=1; i<n; i++)
    {
        min=INF;
        for(j=1; j<=n; j++)
        {
            if(min>dis[j]&&tag[j]==false)
            {
                min=dis[j];
                local=j;
            }
        }
        tag[local]=true;
        for(j=1; j<=n; j++)
        {
            ndis=dis[local]+map[local][j];
            if(tag[j]==false&&ndis<dis[j]&&map[local][j]!=INF)
            {
                dis[j]=ndis;
            }
        }
    }
    return dis[n];
}

int binary()                      //二分枚举最小的最大边
{
    int first,last,mid;
    first=0;
    last=p-1;
    while(first<=last)
    {
        mid=(first+last)>>1;
        inite(edge[mid].w);
        if(djk()<=k)
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;
        }
    }
    return first;
}

int main()
{
    int i,value;
    while(scanf("%d%d%d",&n,&p,&k)!=EOF)
    {
        for(i=0; i<p; i++)
        {
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
        }
        sort(edge,edge+p,cmp);
        inite(0);
        value=djk();
        if(value==INF)                   //注意不连通的情况
        {
            printf("-1\n");
        }
        else if(value<=k)                //注意不需要额外花费的情况
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",edge[binary()].w);
        }
    }
}
