#include<stdio.h>
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int i,j,k,t,dp[100005],n,m,v,s,temp;
    char cha;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
                    
                    scanf("%d%d",&n,&m);
                    for(i=0;i<=n;i++)dp[i]=0;
                    for(i=0;i<m;i++)
                    {
                                    scanf("%d%d %c",&v,&s,&cha);
                                    //printf("%d\n",cha);
                                    if(cha==78)
                                    {
                                               for(j=v;j<=n;j++)
                                               {
                                                                temp=dp[j-v]+s;
                                                                if(dp[j]<temp)dp[j]=temp;
                                               }
                                               //for(j=0;j<=n;j++)printf("%d ",dp[j]);
                                               //printf("\n\n");
                                    }
                                    else
                                    {
                                               for(j=n;j>=v;j--)
                                               {
                                                                temp=dp[j-v]+s;
                                                                if(dp[j]<temp)dp[j]=temp;
                                               }
                                               //for(j=0;j<=n;j++)printf("%d ",dp[j]);
                                               //printf("\n");
                                    }
                    }
                    printf("%d\n",dp[n]);
    }
    return 0;
}
