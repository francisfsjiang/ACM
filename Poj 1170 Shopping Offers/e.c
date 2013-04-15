#include<stdio.h>
#include<string.h>
int dp[6][6][6][6][6],cheapcase[105][15],cheapvalue[105],data[1005][3],number[7];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int s,b,n,i,j,sign[6],i1,i2,i3,i4,i5;
    int min(int x,int y);
    scanf("%d",&b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&number[i]);
        scanf("%d%d",&data[number[i]][0],&data[number[i]][1]);
    }
    scanf("%d",&s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&cheapcase[i][0]);
        for(j=1;j<=cheapcase[i][0];j++)scanf("%d%d",&cheapcase[i][j*2-1],&cheapcase[i][j*2]);
        scanf("%d",&cheapvalue[i]);
    }

    for(i1=0;i1<=data[number[0]][0];i1++)
    for(i2=0;i2<=data[number[1]][0];i2++)
    for(i3=0;i3<=data[number[2]][0];i3++)
    for(i4=0;i4<=data[number[3]][0];i4++)
    for(i5=0;i5<=data[number[4]][0];i5++)dp[i1][i2][i3][i4][i5]=i1*data[number[0]][1]+i2*data[number[1]][1]+i3*data[number[2]][1]+i4*data[number[3]][1]+i5*data[number[4]][1];
    dp[0][0][0][0][0]=0;
    for(i=0;i<b;i++)
    {
        sign[0]=cheapcase[i][2];
        sign[1]=cheapcase[i][4];
        sign[2]=cheapcase[i][6];
        sign[3]=cheapcase[i][8];
        sign[4]=cheapcase[i][10];
        //printf("%d,%d,%d,%d,%d-----------\n",sign[0],sign[1],sign[2],sign[3],sign[4]);
        for(i1=sign[0];i1<=data[cheapcase[i][1]][0];i1++)
        for(i2=sign[1];i2<=data[cheapcase[i][3]][0];i2++)
        for(i3=sign[2];i3<=data[cheapcase[i][5]][0];i3++)
        for(i4=sign[3];i4<=data[cheapcase[i][7]][0];i4++)
        for(i5=sign[4];i5<=data[cheapcase[i][9]][0];i5++)
        {
            if(dp[i1][i2][i3][i4][i5]==0)dp[i1][i2][i3][i4][i5]=dp[i1-sign[0]][i2-sign[1]][i3-sign[2]][i4-sign[3]][i5-sign[4]]+cheapvalue[i];
            else dp[i1][i2][i3][i4][i5]=min(dp[i1][i2][i3][i4][i5],dp[i1-sign[0]][i2-sign[1]][i3-sign[2]][i4-sign[3]][i5-sign[4]]+cheapvalue[i]);
            //printf("%d,%d,%d,%d,%d=%d\n",i1,i2,i3,i4,i5,dp[i1][i2][i3][i4][i5]);
        }
    }
    printf("%d\n",dp[data[number[0]][0]][data[number[1]][0]][data[number[2]][0]][data[number[3]][0]][data[number[4]][0]]);
    return 0;
}

int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}
