#include <stdio.h>
#include <string.h>
int l1,l2,i,j,m,n,k,t;
char  s1[210],s2[210],s3[500];
int dp[210][210];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%s %s %s",s1,s2,s3);
        l1=strlen(s1);
        l2=strlen(s2);
        if(s3[0]==s1[0])dp[1][0]=1;
        else if(s3[0]==s2[0])dp[0][1]=1;
        for(i=1;i<=l1;i++)for(j=1;j<=l2;j++)
        {
            if(dp[i-1][j]==1)
            {
                if(s3[i+j-1]==s1[i-1])dp[i][j]=1;
                if(s3[i+j-1]==s2[j])dp[i-1][j+1]=1;
            }
            else if(dp[i][j-1]==1)
            {
                if(s3[i+j-1]==s1[i])dp[i+1][j-1]=1;
                if(s3[i+j-1]==s2[j-1])dp[i][j]=1;
            }
        }
        /*for(i=0;i<=l1;i++)
        {
            for(j=0;j<=l2;j++)printf("%d ",dp[i][j]);
            printf("\n");
        }*/
        if(dp[l1][l2]==1)printf("Data set %d: yes\n",k+1);
        else printf("Data set %d: no\n",k+1);
    }
    return 0;
}
