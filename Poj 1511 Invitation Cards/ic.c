#include<stdio.h>
#include<string.h>
#define MAX 1000050
int map[MAX][5];
int nextx[MAX];
int nexty[MAX];
int dist[MAX];
int in[MAX];
int spfa[15000000];
int n,m,last;
void insert()
{
    int x,y,d;
    scanf("%d%d%d",&x,&y,&d);
    map[last][0]=x;
    map[last][1]=y;
    map[last][2]=d;
    map[last][3]=nextx[x];
    map[last][4]=nexty[y];
    nextx[x]=last;
    nexty[y]=last;
    last++;
}

long long  spfa1()
{
    int head=0,end=1,i,d;
    memset(in,0,sizeof(in));
    memset(dist,-1,sizeof(dist));
    dist[1]=0;
    in[1]=1;
    spfa[0]=1;
    while(head<end)
    {
        d=spfa[head];
        for(i=nextx[d];;)
        {
            if(dist[d]+map[i][2]<dist[map[i][1]]||dist[map[i][1]]==-1)
            {
                dist[map[i][1]]=dist[d]+map[i][2];
                if(!in[map[i][1]])
                {
                    in[map[i][1]]=1;
                    spfa[end]=map[i][1];
                    end++;
                }
            }
            i=map[i][3];
            if(i==0)break;
        }
        in[d]=0;
        head++;
    }
    long long sum=0;
    for(i=2;i<=n;i++)sum+=dist[i];
    return sum;
}

long long  spfa2()
{
    int head=0,end=1,i,d;
    memset(in,0,sizeof(in));
    memset(dist,-1,sizeof(dist));
    dist[1]=0;
    spfa[0]=1;
    in[1]=1;
    while(head<end)
    {
        d=spfa[head];
        for(i=nexty[d];;)
        {
            if(dist[d]+map[i][2]<dist[map[i][0]]||dist[map[i][0]]==-1)
            {
                dist[map[i][0]]=dist[d]+map[i][2];
                if(!in[map[i][0]])
                {
                    in[map[i][0]]=1;
                    spfa[end]=map[i][0];
                    end++;
                }
            }
            i=map[i][4];
            if(i==0)break;
        }
        in[d]=0;
        head++;
    }
    long long  sum=0;
    for(i=2;i<=n;i++)sum+=dist[i];
    return sum;
}


int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(nextx,0,sizeof(nextx));
        memset(nexty,0,sizeof(nexty));
        last=1;
        for(i=0;i<m;i++)insert();
        /*for(i=0;i<last;i++)printf("%d %d %d %d %d\n",map[i][0],map[i][1],map[i][2],map[i][3],map[i][4]);
        for(i=1;i<=n;i++)printf("%d ",nextx[i]);
        printf("\n");
        for(i=1;i<=n;i++)printf("%d ",nexty[i]);
        printf("\n");*/
        printf("%I64d\n",spfa1()+spfa2());
    }
    return 0;
}
