#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int data[5005],plus,sum,i,n;
    data[0]=0;
    data[1]=0;
    sum=1;
    plus=2;
    for(i=2;i<=5000;i++)
    {
        data[i]=data[i-1]*2+sum;
        sum+=plus;
        plus*=2;
        if(data[i]>=2007)data[i]=data[i]%2007;
        if(sum>=2007)sum=sum%2007;
        if(plus>=2007)plus=plus%2007;
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",(data[n]+n)%2007);
    }
    return 0;
}
