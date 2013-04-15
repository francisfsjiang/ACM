#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int data[105][105];
    int t[105];
    int dp[105];
    int n,i,j,k,max;
    while(scanf("%d",&n)!=EOF)
    {
        memset(data,0,sizeof(data));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&data[i][j]);
        max=0;
        for(i=1;i<=n;i++)
        {
            memset(t,0,sizeof(t));
            for(j=i;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    t[k]+=data[j][k];
                    if(t[k]+dp[k-1]>0)dp[k]=t[k]+dp[k-1];
                    else dp[k]=0;
                    if(dp[k]>max)max=dp[k];
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
