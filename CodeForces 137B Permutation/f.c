#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int data[5005]={0};
    int n,i,sum=0,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(data[x]==1||x>n)
        {
            sum++;
        }
        else
        {
            data[x]=1;
        }
    }
    printf("%d\n",sum);
    return 0;
}
