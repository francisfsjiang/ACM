#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int sum,n,a,b,i,max=0;
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        sum-=a;
        if(sum>max)
        {
            max=sum;
            //printf("%d\n",min);
        }
        sum+=b;
        if(sum>max)
        {
            max=sum;
            //printf("%d\n",min);
        }
    }
    printf("%d",max);
    return 0;
}
