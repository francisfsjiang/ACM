#include<stdio.h>
#include<string.h>
int dp[10][10][10][10];
int used[10][10][10][10];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,x,sign,i,temp;
    int x1,x2,x3,x4;
    int search(int x1,int x2,int x3,int x4);
    //int  change(int *a,int *b);
    memset(dp,-1,sizeof(dp));
    memset(used,0,sizeof(used));
    dp[0][0][0][1]=0;
    search(0,0,0,1);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x1,&x2,&x3,&x4);
        //sign=search(x1,x2,x3,x4);
        if(dp[x1][x2][x3][x4]==0)printf("0\n");
        else printf("1\n");
        //if(number0==0||shift!=0)sign=1;
        //else if
    }
    return 0;
}

int search(int x1,int x2,int x3,int x4)
{
    /*printf("search %d %d %d %d\n",x1,x2,x3,x4);
    change(&x1,&x2);
    change(&x2,&x3);
    change(&x3,&x4);
    change(&x1,&x2);
    change(&x2,&x3);
    change(&x1,&x2);
    printf("search sort%d %d %d %d-%d\n",x1,x2,x3,x4,d);*/


    /*if(dp[x1][x2][x3][x4]!=-1)
    {
        return 1;
    }
    else
    {*/
        if(used[x1][x2][x3][x4]==1)return;
        int sign,i;
        //if(dp[x1][x2][x3][x4]!=-1)return 0;
        if(dp[x1][x2][x3][x4]==0)sign=1;
        else sign=0;
        printf("search %d %d %d %d=%d\n",x1,x2,x3,x4,dp[x1][x2][x3][x4]);
        for(i=1;i<=3&&x1+i<=9;i++)if(dp[x1+i][x2][x3][x4]==-1)dp[x1+i][x2][x3][x4]=sign;
        for(i=1;i<=3&&x2+i<=9;i++)if(dp[x1][x2+i][x3][x4]==-1)dp[x1][x2+i][x3][x4]=sign;
        for(i=1;i<=3&&x3+i<=9;i++)if(dp[x1][x2][x3+i][x4]==-1)dp[x1][x2][x3+i][x4]=sign;
        for(i=1;i<=3&&x4+i<=9;i++)if(dp[x1][x2][x3][x4+i]==-1)dp[x1][x2][x3][x4+i]=sign;
        used[x1][x2][x3][x4]=1;
        for(i=1;i<=3&&x1+i<=9;i++)search(x1+i,x2,x3,x4);
        for(i=1;i<=3&&x2+i<=9;i++)search(x1,x2+i,x3,x4);
        for(i=1;i<=3&&x3+i<=9;i++)search(x1,x2,x3+i,x4);
        for(i=1;i<=3&&x4+i<=9;i++)search(x1,x2,x3,x4+i);
}
