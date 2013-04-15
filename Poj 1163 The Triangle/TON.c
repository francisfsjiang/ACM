#include<stdio.h>
#include<string.h>
int main()
{
     freopen("in.in","r",stdin);
     freopen("out.out","w",stdout);
     int data[101][101],dp[101][101];
     int n,i,j;
     int max(int x,int y);
     while(scanf("%d",&n)!=EOF)
     {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)for(j=1;j<=i;j++)scanf("%d",&data[i][j]);
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)printf("%d ",data[i][j]);
            printf("\n");
        }*/
        for(i=n;i>=1;i--)for(j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+data[i][j];
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)printf("%d ",dp[i][j]);
            printf("\n");
        }*/
        printf("%d\n",dp[1][1]);
     }
     return 0;
}

int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}
