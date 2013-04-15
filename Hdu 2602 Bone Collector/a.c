#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,i,j,n,v,dp[1005],data[1005][2];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&v);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)scanf("%d",&data[i][0]);
        for(i=1;i<=n;i++)scanf("%d",&data[i][1]);
        for(i=1;i<=n;i++)
        {
            for(j=v;j>=data[i][1];j--)
            {
                if(dp[j]<dp[j-data[i][1]]+data[i][0])
                {
                    dp[j]=dp[j-data[i][1]]+data[i][0];
                }
            }
        }
        printf("%d\n",dp[v]);
    }
    return 0;
}

