#include<stdio.h>
#include<string.h>
#define MAX 120
double data[MAX][MAX];
double cost[MAX][MAX];
int use[MAX];
int spfa[3000000];
double money[MAX];
int in[MAX];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,n,m,x,y,head,end,d;
    double sum;
    while(scanf("%d%d%d",&n,&m,&spfa[0])!=EOF)
    {
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)data[i][j]=-1;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)cost[i][j]=-1;
        for(i=1;i<=n;i++)money[i]=0;
        //memset(use,0,sizeof(use));
        memset(in,0,sizeof(in));
        scanf("%lf",&sum);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            scanf("%lf%lf%lf%lf",&data[x][y],&cost[x][y],&data[y][x],&cost[y][x]);
        }
        int sign=0;
        head=0;
        end=1;
        in[spfa[0]]=1;
        money[spfa[0]]=sum;
        while(head<end)
        {
            d=spfa[head];
            for(i=1;i<=n;i++)
            {
                if(data[i][j]!=-1&&(money[d]-cost[d][i])*data[d][i]>money[i])//&&use[i]<=200*n
                {
                    money[i]=(money[d]-cost[d][i])*data[d][i];
                    if(in[i]==0)
                    {
                        spfa[end]=i;
                        end++;
                        in[i]=1;
                    }
                    if(money[spfa[0]]>sum)
                    {
                        //for(i=1;i<=n;i++)printf("%lf\n",money[i]);
                        sign=1;
                        break;
                    }
                }
            }
            if(sign==1)break;
            in[d]=0;
            head++;
        }
        //for(i=1;i<=n;i++)printf("%lf\n",money[i]);
        if(sign==0)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
