#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    long long sum,x,n,i;
    scanf("%I64d",&n);
    sum=0;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&x);
        sum+=x*i-i+1;
        //printf("%I64d\n%I64d\n",x,x*i-i+1);
    }
    printf("%I64d",sum);
    return 0;
}
