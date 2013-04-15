#include<stdio.h>
int main()
{
    long long i,j;
    long long sum,temp;
    scanf("%I64d",&sum);
    for(i=2;i*i<=sum;i++)
    {
        if(sum%i==0)
        {
            temp=sum/i;
            //printf("%I64d\n",temp);
            for(j=2;j*j<=temp;j++)
            {
                if(temp%j==0)
                {
                    printf("1\n%I64d",i*j);
                    return 0;
                }
            }
            printf("2");
            return 0;
        }
    }
    printf("1\n0");
    return 0;
}
