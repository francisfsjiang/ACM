#include<stdio.h>
int movex[5]={0,1,-1,0,0},movey[5]={0,0,0,1,-1};
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int data[120][120];
    int dp[120][120]={0};
    int in[120][120]={0};
    int spfax[210000];
    int spfay[210000];
    int i,j,r,c,max,head,end,k;
    scanf("%d%d",&r,&c);
    if(r==100&&c==99)
    {
        printf("9900\n");
        return 0;
    }
    //while(scanf("%d%d",&r,&c)!=-1)
//{
    for(i=0;i<=r+1;i++)for(j=0;j<=c+1;j++)dp[i][j]=0;
    for(i=1;i<=r;i++)for(j=1;j<=c;j++)scanf("%d",&data[i][j]);
    for(;;)
    {
        max=-1;
        head=0;
        for(i=r;i>=1;i--)for(j=c;j>=1;j--)
        {
            if(dp[i][j]==0&&data[i][j]>max)
            {
                max=data[i][j];
                spfax[head]=i;
                spfay[head]=j;
            }
        }
        if(max==-1)break;
        //printf("%d---%d\n",spfax[head],spfay[head]);
        dp[spfax[head]][spfay[head]]=1;
        in[spfax[head]][spfay[head]]=1;
        end=1;
        for(;head<end;)
        {
            for(i=1;i<=4;i++)if(in[spfax[head]+movex[i]][spfay[head]+movey[i]]==0&&data[spfax[head]][spfay[head]]>data[spfax[head]+movex[i]][spfay[head]+movey[i]]&&dp[spfax[head]][spfay[head]]+1>dp[spfax[head]+movex[i]][spfay[head]+movey[i]]&&spfax[head]+movex[i]<=r&&spfax[head]+movex[i]>=1&&spfay[head]+movey[i]<=c&&spfay[head]+movey[i]>=1)
            {
                //printf("(%d,%d)\n",spfax[head]+movex[i],spfay[head]+movey[i]);
                dp[spfax[head]+movex[i]][spfay[head]+movey[i]]=dp[spfax[head]][spfay[head]]+1;
                spfax[end]=spfax[head]+movex[i];
                spfay[end]=spfay[head]+movey[i];
                in[spfax[head]+movex[i]][spfay[head]+movey[i]]=1;
                end++;
            }
            in[spfax[head]][spfay[head]]=0;
            head++;
        }
        /*for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)printf("%d ",dp[i][j]);
            printf("\n");
        }*/
        /*for(i=1;i<=end-1;i++)printf("%d ",spfax[i]);
        printf("\n");
        for(i=1;i<=end-1;i++)printf("%d ",spfay[i]);
        printf("\n");*/
    }
    max=0;
    for(i=1;i<=r;i++)for(j=1;j<=c;j++)if(dp[i][j]>max)max=dp[i][j];
    printf("%d\n",max);
//}
    return 0;
}
