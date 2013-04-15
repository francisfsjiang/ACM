#include<stdio.h>
#include<string.h>
#include<math.h>
int jump[1000][1000]={0};
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int dp[22][1005];
    int data[22][1005];
    int max(int x,int y);
    int C,i,j,k,n,m;
    for(i=1;i<=1000;i++)
    {
        for(j=i*2;j<=1000;j+=i)jump[i][j]=1;
    }
    scanf("%d",&C);
    while(C--)
    {

        scanf("%d%d",&n,&m);
        memset(dp,-10000,sizeof(dp));
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&data[i][j]);
        dp[0][1]=0;
        dp[1][0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                for(k=1;k<=j;k++)
                {
                    if(jump[k][j]==1)
                    {
                        dp[i][j]=max(dp[i][j],dp[i][k]);
                    }
                }
                dp[i][j]+=data[i][j];
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}
