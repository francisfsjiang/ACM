#include<stdio.h>
#include<string.h>
int data[31][31], dp[62][31][31] ;
int main()
{
    int max(int a,int b,int c,int d);
    int n,i,j,k ;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&data[i][j]) ;
        memset(dp,0,sizeof(dp)) ;
        for(k=1;k<2*n-2;k++)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(i==j)continue;
                    dp[k][i][j]=max(dp[k-1][i][j],dp[k-1][i-1][j],dp[k-1][i][j-1],dp[k-1][i-1][j-1]);
                    dp[k][i][j]+=data[i][k-i]+data[j][k-j];
                }
            }
        }
        dp[k][n-1][n-1]=max(dp[k-1][n-2][n-1],dp[k-1][n-1][n-2],0,0)+data[n-1][n-1]+data[0][0] ;
        printf("%d\n",dp[k][n-1][n-1]);
    }
    return 0 ;
}

int max(int a,int b,int c,int d)
{
    if(a>=b&&a>=c&&a>=d)return a;
    if(b>=a&&b>=c&&b>=d)return b;
    if(c>=a&&c>=b&&c>=d)return c;
    if(d>=a&&d>=b&&d>=c)return d;
}
