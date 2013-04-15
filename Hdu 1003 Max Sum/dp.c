#include<stdio.h>
#include<string.h>
int re[100005];
int data[100005];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,t,n,max,maxn,result,m;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        if(k!=1)printf("\n");
        scanf("%d",&n);
        memset(re,0,sizeof(re));
        for(i=0;i<n;i++)scanf("%d",&data[i]);
        re[0]=data[0];
        max=re[0];
        maxn=0;
        /*for(i=1;i<=n;i++)printf("%d ",re[i][0]);
        printf("\n");*/
        for(i=1;i<n;i++)
        {
            if(re[i-1]<0)re[i]=data[i];
            else re[i]=re[i-1]+data[i];
            if(max<re[i])
            {
                max=re[i];
                maxn=i;
            }
        }
        if(max<0)
        {
            printf("Case %d:\n",k);
            printf("%d %d %d\n",max,maxn+1,maxn+1);
        }
        else
        {
            for(i=maxn;i>=0;i--)
            {
                if(re[i]<0)break;
            }
            printf("Case %d:\n",k);
            printf("%d %d %d\n",max,i+2,maxn+1);
        }
    }
    return 0;
}

