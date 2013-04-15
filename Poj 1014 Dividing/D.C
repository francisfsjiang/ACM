#include<stdio.h>
#include<string.h>
int data[10],dp[400005];
int main()
{
    int i,j,t,sum,k,d;
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    for(t=1;t<=10000;t++)
    {
        sum=0;
        if(t!=1)printf("\n");
        for(i=1;i<=6;i++)
        {
            scanf("%d",&data[i]);
            sum+=data[i]*i;
        }
        //printf("%d\n",sum);
        if(sum==0)break;
        if(sum%2==1)
        {
            printf("Collection #%d:\nCan't be divided.\n",t);
            continue;
        }
        sum=sum/2;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=6;i++)
        {
            if(data[i]==0)continue;
            //printf("------------\n");
            for(k=1;;)
            {
                d=k*i;
                //printf("%d %d \n",k,d);
                for(j=sum+1;j>=d;j--)
                {
                    if(dp[j]<dp[j-d]+d)dp[j]=dp[j-d]+d;
                }
                data[i]-=k;
                k=k*2;
                /*for(j=0;j<=sum;j++)printf("%d ",dp[i]);
                printf("\n");*/
                if(data[i]==0)break;
                else if(data[i]-k<0)k=data[i];
            }
        }
        if(dp[sum]==sum)printf("Collection #%d:\nCan be divided.\n",t);
        else printf("Collection #%d:\nCan't be divided.\n",t);
    }
    return 0;
}
