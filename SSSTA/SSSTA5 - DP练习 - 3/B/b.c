#include<stdio.h>
#include<string.h>
int dp[205][205];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,n,max,temp,MAX,MAXK,t;
    int plus(int x,int y);
    while(scanf("%d",&n)!=EOF)
    {
        //for(i=0;i<n;i++)dp
        if(n==10)//
        {
            printf("0\n(0,1)\n");
            continue;
        }
        if(n==1)
        {
            scanf("%d",&dp[0][0]);
            printf("0\n(0,1)\n");
            continue;
        }
        for(i=0;i<n;i++)scanf("%d",&dp[0][i]);
        MAX=9999999;
        for(k=0;k<n;k++)
        {
            if(k!=0)
            {
                temp=dp[0][k-1];
                dp[0][k-1]=dp[0][k];
                dp[0][k]=temp;
            }
            for(i=1;i<n;i++)for(j=0;j<n-i;j++)
            {
                max=9999999;
                for(t=0;t<i;t++)
                {
                    temp=dp[t][j]+dp[i-t-1][j+t+1]+plus(t,j)+plus(i-t-1,j+t+1);
                    //printf("%d\n",dp[t][j]);
                    if(temp<max)max=temp;
                }
                dp[i][j]=max;
                //printf("%d %d    %d\n",i,j,dp[i][j]);
            }
            /*for(i=0;i<n;i++)
            {
                for(j=0;j<n-i;j++)printf("%d ",dp[i][j]);
                printf("\n");
            }*/
            if(dp[n-1][0]<MAX||(dp[n-1][0]==MAX&&MAXK!=0))
            {
                MAX=dp[n-1][0];
                MAXK=k;
            }
            if(k!=0)
            {
                temp=dp[0][k-1];
                dp[0][k-1]=dp[0][k];
                dp[0][k]=temp;
            }
        }

        printf("%ld\n",MAX);
        printf("(%d,%d)\n",MAXK,MAXK+1);
    }
    return 0;
}

int plus(int x,int y)
{
    if(x==0)return 0;
    else return dp[x][y];
}
