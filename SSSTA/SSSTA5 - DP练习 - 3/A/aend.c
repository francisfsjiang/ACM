#include<stdio.h>
#define max(x,y) x>y?x:y
#define size 5100
int maxlen[size];//��¼��ǰ��1���㵽��i����֮�����½����г���
int maxnum[size];//��¼��ǰ��1���㵽��i����֮�����½����и���
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
        for(i=1;i<=n;i++)//����½�����
        {
            for(j=1;j<i;j++)
            {
                if(a[i]<a[j])
                {
                    maxlen[i]=max(maxlen[i],maxlen[j]+1);
                }
            }
        }
        for(i=1;i<=n;i++)if(maxlen[i]==1)maxnum[i]=1;//��ʼ��
        for(i=1;i<=n;i++)//������½������еĸ���
        {
            for(j=i-1;j>0;j--)
            {
                if(a[j]>a[i])
                {
                    if(maxlen[j]+1==maxlen[i])//�ҵ�һ�����е�ǰһ����
                    {
                        maxnum[i]+=maxnum[j];
                    }
                }
                if(a[j]==a[i])
                {
                    if(maxlen[i]==1)maxnum[i]=0;//���������һ����ͬ��������û���ҵ�����Ҫ������У���Ϊ�˱����ظ���ֵΪ0
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
