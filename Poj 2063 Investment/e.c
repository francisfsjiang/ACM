#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,t,k,orign,year,d,data[12][2],dp[46000],now;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&orign,&year,&d);
        for(i=1;i<=d;i++)
        {
            scanf("%d%d",&data[i][0],&data[i][1]);
            data[i][0]=data[i][0]/1000;
        }
        /*for(i=1;i<=d;i++)printf("%d ",data[i][0]);
        printf("\n");
        for(i=1;i<=d;i++)printf("%d ",data[i][1]);
        printf("\n");*/
        for(i=1;i<=year;i++)
        {
            now=orign/1000;
            //printf("%d\n",now);
            for(k=0;k<=now;k++)dp[k]=0;
            /*for(k=0;k<=now;k++)printf("%d ",dp[k]);
            printf("\n");*/
            for(j=1;j<=d;j++)
            {
                for(k=data[j][0];k<=now;k++)
                {
                    if(dp[k]<dp[k-data[j][0]]+data[j][1])dp[k]=dp[k-data[j][0]]+data[j][1];
                }
                /*for(k=data[i][0];k<=now;k++)printf("%d ",dp[k]);
                printf("\n");*/
            }
            orign+=dp[now];
            //printf("%d\n",orign);
        }
        printf("%d\n",orign);
    }
    return 0;
}
