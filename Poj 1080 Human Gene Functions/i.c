#include<stdio.h>
#include<string.h>
int dp[102][102][2];
int point[5][5]={
{5,-1,-2,-1,-3},
{-1,5,-3,-2,-4},
{-2,-3,5,-2,-2},
{-1,-2,-2,5,-1},
{-3,-4,-2,-1,0}};
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,i,j,l1,l2,sum,temp1,temp2,temp3;
    int dp[105][105];
    int max(int x,int y,int z);
    char s1[200],s2[200],tm[200];
    int x(char c1,char c2);
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-999999,sizeof(dp));
        scanf("%d",&l1);
        scanf("%s",s1);
        scanf("%d",&l2);
        scanf("%s",s2);
        //printf("%s\n%s\n",s1,s2);
        dp[0][0]=0;
        for(i=1;i<=l1;i++)dp[i][0]=dp[i-1][0]+x(s1[i-1],'-');
        for(j=1;j<=l2;j++)dp[0][j]=dp[0][j-1]+x('-',s2[j-1]);
        for(i=1;i<=l1;i++)for(j=1;j<=l2;j++)
        {
            temp1=dp[i-1][j]+x(s1[i-1],'-');
            temp2=dp[i][j-1]+x('-',s2[j-1]);
            temp3=dp[i-1][j-1]+x(s1[i-1],s2[j-1]);
            dp[i][j]=max(temp1,temp2,temp3);
        }
        printf("%d\n",dp[l1][l2]);
    }
    return 0;
}

int x(char c1,char c2)
{
    int a,b;
    if(c1=='A')a=0;
    else if(c1=='C')a=1;
    else if(c1=='G')a=2;
    else if(c1=='T')a=3;
    else a=4;
    if(c2=='A')b=0;
    else if(c2=='C')b=1;
    else if(c2=='G')b=2;
    else if(c2=='T')b=3;
    else b=4;
    return point[a][b];
}

int max(int x,int y,int z)
{
    if(x>=y&&x>=z)return x;
    if(y>=x&&y>=z)return y;
    if(z>=x&&z>=y)return z;
}
