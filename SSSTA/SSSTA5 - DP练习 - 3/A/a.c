#include<stdio.h>
int  data[5005];
int  dp[5005];
int  link[5005];
int  re[5005][501];
int main()
{
    int i,j,k=0,n;
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%ld",&n);
	for(i=1;i<=n;i++)scanf("%ld",&data[i]);
	n++;
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j>=1;j--)if(data[j]>data[i]&&dp[j]>dp[i])dp[i]=dp[j];
		dp[i]++;
	}
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)if(data[i]==data[j])
	{
        link[i]=j;
        break;
    }
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)if((link[j]==0||link[j]>i)&&dp[j]==dp[i]-1&&data[j]>data[i])
        {
            for(k=1;k<=re[j][0];k++)
            {
                re[i][k]+=re[j][k];
                re[i][k+1]+=re[i][k]/10;
                re[i][k]%=10;
            }
            while(re[i][k]>=10)
            {
                re[i][k+1]+=re[i][k]/10;
                re[i][k]%=10;
                k++;
            }
            while(re[i][k]==0)k--;
            if(k>=re[i][0])re[i][0]=k;
        }
		if(re[i][0]==0)
		{
            re[i][0]=1;
            re[i][1]=1;
        }
	}
	printf("%ld ",dp[n]-1);
	for(i=re[n][0];i>=1;i--)printf("%ld",re[n][i]);

    printf("\n");
    printf("\n");
	for(i=1;i<=n;i++)printf("%2d ",i);
	printf("\n");
	for(i=1;i<=n;i++)printf("%2d ",data[i]);
	printf("\n");
	for(i=1;i<=n;i++)printf("%2d ",dp[i]);
	printf("\n");
	for(i=1;i<=n;i++)printf("%2d ",link[i]);
	printf("\n");
	for(i=1;i<=n;i++)printf("%2d ",data[i]);
	printf("\n");
	for(i=1;i<=n;i++)printf("%2d ",re[i][0]);
	printf("\n");
	for(i=1;i<=n;i++)printf("%2d ",re[i][1]);
	printf("\n");
	//printf("%2d ",re[n][i]);
	printf("\n");
	return 0;
}
