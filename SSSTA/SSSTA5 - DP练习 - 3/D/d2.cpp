#include<stdio.h>
#include<string.h>
#define min(x,y) x>y?y:x
char str[1000];
char word[1000][30];
int dp[1000];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,len,i,j,pos,k,tmp;
    while(scanf("%d%d",&n,&len)!=EOF)
    {
        scanf("%s",str);
        for(i=0;i<n;i++)scanf("%s",word[i]);
        dp[0]=0;
        for(i=1;i<=len;i++)
        {
            dp[i]=dp[i-1]+1;
            for(j=0;j<n;j++)
            {
                tmp=k=strlen(word[j]);
                k-=1;
                pos=i-1;
                while(pos>=0&&k>=0)
                {
                    if(str[pos]==word[j][k])k--;
                    pos--;
                }
                if(k<0)
                {
                    dp[i]=min(dp[i],dp[pos+1]+i-pos-1-tmp);
                }
            }
            //for(j=0;j<=len;j++)printf("%d ",dp[j]);
            //printf("\n");
        }
        printf("%d\n",dp[len]);
    }
    return 0;
}
