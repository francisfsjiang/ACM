#include<stdio.h>
#include<string.h>
int data[31][31];
int dp[63][31][31];
int main()
{
    int max(int a,int b,int c,int d);
    int n,m;
    int i,j,k;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&data[i][j]);
        for(k=1;k<=n*2-2;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
        {
            if(i==n&&j==n&&k==n*2-2)dp[k][i][j]=max(dp[k-1][i-1][j],dp[k-1][i][j-1],dp[k-1][i][j],dp[k-1][i-1][j-1])+data[i][k+2-i]+data[j][k+2-j];
            else  if(i!=j&&k+2-i>=1&&k+2-j>=1)dp[k][i][j]=max(dp[k-1][i-1][j],dp[k-1][i][j-1],dp[k-1][i][j],dp[k-1][i-1][j-1])+data[i][k+2-i]+data[j][k+2-j];
            //if(i==j&&k!=n*2-2)continue;
            //dp[k][i][j]=max(dp[k-1][i-1][j],dp[k-1][i][j-1],dp[k-1][i][j],dp[k-1][i-1][j-1])+data[i][k+2-i]+data[j][k+2-j];
        }
        /*for(k=1;k<=n*2-2;k++)
        {
            printf("k=%d\n",k);
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)printf("%d ",dp[k][i][j]);
                printf("\n");
            }
        }*/
        printf("%d\n",dp[n*2-2][n][n]);
    }
    return 0;
}

int max(int a,int b,int c,int d)
{
    if(a>=b&&a>=c&&a>=d)return a;
    if(b>=a&&b>=c&&b>=d)return b;
    if(c>=a&&c>=b&&c>=d)return c;
    if(d>=a&&d>=b&&d>=c)return d;
}
