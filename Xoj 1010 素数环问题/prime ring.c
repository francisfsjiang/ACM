#include<stdio.h>
int data[100]={0};
int ring[100];
int prime[100]={0};
int n;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j;
    int search(int x);
    for(i=2;i<=50;i++)
    {
        if(prime[i]==0)for(j=i*2;j<=50;j+=i)prime[j]=1;
    }
    /*for(i=1;i<=50;i++)printf("%2d ",i);
    printf("\n");
    for(i=1;i<=50;i++)printf("%2d ",prime[i]);
    printf("\n");*/
    int sign=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)data[i]=0;
        data[1]=1;
        ring[1]=1;
        printf("Case %d:\n",sign);
        sign++;
        search(n-1);
        printf("\n");
    }
    return 0;
}

int search(int x)//ring[n-x+1]
{
    int i;
    if(x==0)
    {
        if(prime[ring[1]+ring[n]]==0)
        {
        for(i=1;i<=n;i++)
        {
            printf("%d",ring[i]);
            if(i!=n)printf(" ");
        }
        printf("\n");
        }
        else return ;
    }
    else
    {
        for(i=2;i<=n;i++)
        {
            if(data[i]==0&&prime[ring[n-x]+i]==0)
            {
                data[i]=1;
                ring[n-x+1]=i;
                search(x-1);
                data[i]=0;
            }
        }
    }
}
