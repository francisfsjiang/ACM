#include<stdio.h>
int main()
{
    int n,i,sum,s;
    sum=0;
    scanf("%d",&s);
    for(i=1;i<=1000;i++)
    {
        sum+=i;
        if(sum>=s&&(sum-s)%2==0)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
