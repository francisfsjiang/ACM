#include<stdio.h>
#define MAX 3000
int brother[MAX];
int child[MAX];
int childn[MAX];
int price[MAX];
int pay[MAX];
int dp[MAX][MAX];
int m,n;
int main()
{
    int x,i,j,last;
    int search(int x);
    int maxs(int x,int y);
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n-m;i++)
    {
        scanf("%d",&childn[i]);
        for(j=1;j<=childn[i];j++)
        {
            scanf("%d",&x);
            scanf("%d",&price[x]);
            if(j==1)
            {
                child[i]=x;
                last=x;
            }
            else
            {
                brother[last]=x;
                last=x;
            }
        }
    }
    for(i=n-m+1;i<=n;i++)scanf("%d",&pay[i]);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)dp[i][j]=-214748364;
    /*for(i=1;i<=n;i++)printf("%d ",child[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%d ",childn[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%d ",brother[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%d ",price[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%d ",pay[i]);
    printf("\n");
    printf("%d\n",);*/
    search(1);
    /*for(i=1;i<=n;i++)
    {
        printf("%d -----",i);
        for(j=0;j<=6;j++)printf("%d ",dp[i][j]);
        printf("\n");
    }
    printf("\n");*/
    int max;
    for(i=n;i>=0;i--)
    {
        if(dp[1][i]>=0)
        {
            max=i;
            break;
        }
    }
    printf("%d\n",max);
    return 0;
}

int maxs(int x,int y)
{
    if(x>y)return x;
    else return y;
}

int search(int x)
{
    if(x>n-m)
    {
        dp[x][1]=pay[x];
        return 1;
    }
    else
    {
        int i,j,k,temp,sum=0;
        dp[x][0]=0;
        for(i=child[x];i!=0;i=brother[i])
        {
            //printf("%d  %d\n",x,i);
            temp=search(i);
            sum+=temp;
            //printf("%d %d\n",i,sum);
            for(j=sum;j>=0;j--)
            {
                for(k=0;k<=temp&&k<=j;k++)//k<=num&&
                {
                    dp[x][j]=maxs(dp[x][j],dp[x][j-k]+dp[i][k]-price[i]);
                    //printf("dp[%d][%d]=maxs(dp[%d][%d],dp[%d][%d]+dp[%d][%d]-%d);==%d\n",x,j,x,j,x,j-k,i,k,price[i],dp[x][j]);
                }
            }
        }
        return sum;
    }
}
