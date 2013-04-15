#include<stdio.h>
#include<string.h>
#define MAX 300
#define INF 99999999
#define min(x,y) x>y?y:x
int con[MAX][MAX]={0};
int data[MAX][MAX]={0};
int in[MAX];
int sbdist[40][MAX]={0};
int summer[MAX];
int m,n,l;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,d,x,j,k,sum,minn;
    while(scanf("%d%d%d",&m,&n,&l)!=EOF)
{
    memset(in,0,sizeof(in));
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
    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)printf("%d ",con[i][j]);
        printf("\n");
    }*/
    for(i=1;i<=m;i++)
    {
        data[i][i]=0;
        for(j=i+1;j<=m;j++)
        {
            sum=0;
            for(k=1;k<=n;k++)
            {
                if(con[i][k]==1&&con[j][k]==1)sum++;
                if(sum>=2)break;
            }
            if(sum>=2)
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
    for(k=1;k<=m;k++)
    {
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(data[i][k]!=-1&&data[k][j]!=-1&&(data[i][j]==-1||data[i][j]>data[i][k]+data[k][j]))data[i][j]=data[i][k]+data[k][j];
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
        for(j=1;j<=m;j++)sbdist[i][j]=INF;
        for(j=1;j<=m;j++)
        {
            if(con[j][sbdist[i][0]]==1)
            {
                for(k=1;k<=m;k++)sbdist[i][k]=min(sbdist[i][k],data[j][k]);
            }
        }
    }
    for(j=1;j<=m;j++)
    {
        summer[j]=0;
        for(i=0;i<l;i++)summer[j]+=sbdist[i][j];
    }
    /*for(j=1;j<=m;j++)printf("%d ",summer[j]);
    printf("\n");*/
    minn=INF;
    for(j=1;j<m;j++)if(minn>summer[j])minn=summer[j];
    printf("%ld",minn);
}
    return 0;
}
