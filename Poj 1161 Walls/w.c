#include<stdio.h>
#include<string.h>
#define MAX 300
#define INF 999999999
int con[MAX][MAX]={0};
int data[MAX][MAX]={0};
int sbdist[40][MAX]={0};
int spfa[2000000];
int in[MAX];
int summer[MAX];
int m,n,l;

int spfas(int x,int start)
{
    //printf("%d %d\n",x,start);
    int head=0,end=1,d,i;
    memset(in,0,sizeof(in));
    spfa[head]=start;
    in[start]=1;
    while(head<end)
    {
        d=spfa[head];
        for(i=1;i<=m;i++)
        {
            if(data[d][i]!=-1&&sbdist[x][d]+data[d][i]<sbdist[x][i])
            {
                sbdist[x][i]=sbdist[x][d]+data[d][i];
                if(!in[i])
                {
                    spfa[end]=i;
                    end++;
                    in[i]=1;
                }
            }
        }
        in[d]=0;
        head++;
    }
    /*for(i=0;i<end;i++)printf("%d ",spfa[i]);
    printf("\n");*/
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,d,x,j,k,sum,min;
    scanf("%d%d%d",&m,&n,&l);
    memset(sbdist,-1,sizeof(sbdist));
    for(i=0;i<l;i++)scanf("%d",&sbdist[i][0]);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&d);
        for(j=1;j<=d;j++)
        {
            scanf("%d",&x);
            con[i][x]=1;
        }
    }
    for(i=1;i<=m;i++)
    {
        data[i][i]=0;
        for(j=i+1;j<=m;j++)
        {
            sum=0;
            for(k=1;k<=n;k++)
            {
                if(con[i][k]==1&&con[j][k]==1)sum++;
                if(sum==2)break;
            }
            if(sum==2)
            {
                data[i][j]=1;
                data[j][i]=1;
            }
            else
            {
                data[i][j]=-1;
                data[j][i]=-1;
            }
        }
    }
    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)printf("%2d ",data[i][j]);
        printf("\n");
    }*/
    for(i=0;i<l;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(con[j][sbdist[i][0]]==1)sbdist[i][j]=0;
            else sbdist[i][j]=INF;
        }
        for(j=1;j<=m;j++)if(con[j][sbdist[i][0]]==1)spfas(i,j);
    }
    /*for(i=0;i<l;i++)
    {
        for(j=0;j<=m;j++)printf("% d ",sbdist[i][j]);
        printf("\n");
    }*/
    for(j=1;j<=m;j++)
    {
        summer[j]=0;
        for(i=0;i<l;i++)summer[j]+=sbdist[i][j];
    }
    for(j=1;j<=m;j++)printf("%d ",summer[j]);
    printf("\n");
    min=INF;
    for(j=1;j<=m;j++)if(min>summer[j])min=summer[j];
    printf("%d",min);
    return 0;
}
