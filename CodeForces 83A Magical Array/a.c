#include<stdio.h>
int main()
{
    int n,i,last,x;
    long long sum,temp;
    scanf("%d",&n);
    scanf("%d",&last);
    temp=1;
    sum=0;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==last)temp++;
        else
        {
            sum+=temp*(temp+1)/2;
            temp=1;
            last=x;
        }
    }
    sum+=temp*(temp+1)/2;
    printf("%I64d",sum);
    return 0;
}
