#include<stdio.h>
#define min(x,y) x>y?y:x
#define MAX 105
#define INF 99999999
int data[MAX][MAX];
int in[MAX];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,n,m,x,miner,minn,max,sign;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)data[i][j]=INF;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&x);
                scanf("%d",&data[i][x]);
            }
        }
        for(i=1;i<=n;i++)data[i][i]=0;
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    data[i][j]=min(data[i][j],data[i][k]+data[k][j]);
                }
            }
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%d ",data[i][j]);
            printf("\n");
        }*/
        minn=INF;
        for(i=1;i<=n;i++)
        {
            sign=0;
            max=data[i][1];
            for(j=2;j<=n;j++)
            {
                if(i==j)continue;
                if(data[i][j]==INF)
                {
                    sign=1;
                    break;
                }
                if(data[i][j]>max)max=data[i][j];
            }
            if(sign==1)continue;
            else if(max<minn)
            {
                minn=max;
                miner=i;
            }
        }
        if(minn==INF)printf("disjoint");
        else printf("%d %d\n",miner,minn);
    }
    return 0;
}
