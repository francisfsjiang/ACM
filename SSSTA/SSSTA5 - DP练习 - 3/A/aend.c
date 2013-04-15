#include<stdio.h>
#define max(x,y) x>y?x:y
#define size 5100
int maxlen[size];//记录当前第1个点到第i个点之间的最长下降序列长度
int maxnum[size];//记录当前第1个点到第i个点之间的最长下降序列个数
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int a[size];
    int n,i,j,maxx,ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            maxnum[i]=0;
            maxlen[i]=1;
        }
        for(i=1;i<=n;i++)//求最长下降序列
        {
            for(j=1;j<i;j++)
            {
                if(a[i]<a[j])
                {
                    maxlen[i]=max(maxlen[i],maxlen[j]+1);
                }
            }
        }
        for(i=1;i<=n;i++)if(maxlen[i]==1)maxnum[i]=1;//初始化
        for(i=1;i<=n;i++)//计算最长下降子序列的个数
        {
            for(j=i-1;j>0;j--)
            {
                if(a[j]>a[i])
                {
                    if(maxlen[j]+1==maxlen[i])//找到一个可行的前一个数
                    {
                        maxnum[i]+=maxnum[j];
                    }
                }
                if(a[j]==a[i])
                {
                    if(maxlen[i]==1)maxnum[i]=0;//如果搜索到一个相同的数后仍没有找到符合要求的序列，则为了避免重复赋值为0
                    break;
                }
            }
        }
        maxx=-1;
        for(i=1;i<=n;i++)
        {
            if(maxlen[i]>maxx)maxx=maxlen[i];
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(maxlen[i]==maxx)ans+=maxnum[i];
        }
        printf("%d %d\n",maxx,ans);
    }
    return 0;
}
