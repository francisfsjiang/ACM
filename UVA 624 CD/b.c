#include<stdio.h>
#include<string.h>
int dp[1005],data[1005],record[25][1005],recordn[25][1005];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,i,j,n,v;
    void pr(int n);
    while(scanf("%d",&v)!=EOF)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)scanf("%d",&data[i]);
        for(i=1;i<=n;i++)
        {
            for(j=v;j>=data[i];j--)
            {
                if(dp[j]<dp[j-data[i]]+1)
                {
                    dp[j]=dp[j-data[i]]+1;
                    record[i][j]=data[i];
                    recordn[i][j]=j-data[i];
                }
            }
            for(j=1;j<=v;j++)printf("%2d ",dp[j]);
            printf("\n");
        }
        printf("\n\n");

        for(i=1;i<=v;i++)printf("%2d ",i);
        printf("\n");
        for(j=1;j<=n;j++)
        {
        for(i=1;i<=v;i++)printf("%2d ",record[j][i]);
        printf("\n");
        }
        printf("\n");
        for(j=1;j<=n;j++)
        {
        for(i=1;i<=v;i++)printf("%2d ",recordn[j][i]);
        printf("\n");
        }
        for(i=1;i<=v;i++)printf("%2d ",dp[i]);
        printf("\n");
        //pr(dp[v]);
        printf("sum:%d\n",dp[v]);
    }
    return 0;
}

/*void pr(int n)
{
    if(n==0)return;
    pr(recordn[n]);
    printf("%d ",data[record[n]]);
}*/
