#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,i,j,n,v,d;
    int data[505][2];
    int dp[10005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&v,&d);
        v=v-n;
        for(i=1;i<=d;i++)scanf("%d%d",&data[i][1],&data[i][0]);
        for(i=0;i<=v;i++)dp[i]=999999;
        dp[0]=0;
        for(i=1;i<=d;i++)
        {
            for(j=data[i][0];j<=v;j++)
            {
                if(dp[j]>dp[j-data[i][0]]+data[i][1])dp[j]=dp[j-data[i][0]]+data[i][1];
            }
        }
        if(dp[v]==999999)printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
    }
    return 0;
}

