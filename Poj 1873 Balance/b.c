#include<stdio.h>
#include<string.h>
int dp[21][15001];
int main()
{
    int C,G,c[21],g[21];
    int i,j,k;
    while(scanf("%d%d",&C,&G)!=EOF)
    {
        for(i=1;i<=C;i++)scanf("%d",&c[i]);
        for(i=1;i<=G;i++)scanf("%d",&g[i]);
        memset(dp,0,sizeof(dp));
        dp[0][7500]=1;
        for(i=1;i<=G;i++)
        {
            for(j=0;j<=15000;j++)
            {
                if(dp[i-1][j])
                {
                    for(k=1;k<=C;k++)
                    {
                        dp[i][j+g[i]*c[k]]+=dp[i-1][j];
                    }
                }
            }
        }
        printf("%d\n",dp[G][7500]);
    }
    return 0;
 }
