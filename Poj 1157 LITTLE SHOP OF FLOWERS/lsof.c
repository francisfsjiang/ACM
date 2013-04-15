#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,f,v,max;
    int data[102][102];
    int dp[102][102]={0};
    scanf("%d%d",&f,&v);
    for(i=1;i<=f;i++)for(j=1;j<=v;j++)scanf("%d",&data[i][j]);
    for(i=0;i<=f;i++)for(j=0;j<=v;j++)dp[i][j]=-500000;
    max=-500000;
    for(j=1;j<=v-f+1;j++)
    {
        if(data[1][j]>max)max=data[1][j];
        dp[1][j]=max;
    }
    for(i=2;i<=f;i++)
    {
        for(j=i;j<=v-f+i;j++)
        {
            if(dp[i][j]<dp[i-1][j-1]+data[i][j])dp[i][j]=dp[i-1][j-1]+data[i][j];
            if(dp[i][j]<dp[i][j-1])dp[i][j]=dp[i][j-1];
        }
    }
    printf("%ld\n",dp[f][v]);
    return 0;
}
