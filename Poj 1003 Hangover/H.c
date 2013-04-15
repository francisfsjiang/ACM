#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,i;
    float sign,sum;
    for(;;)
    {
        scanf("%f",&sign);
        if(sign==0)break;
        sum=0;
        for(i=1;sum<sign;i++)
        {
            sum+=1.0/(i+1);
        }
        printf("%d card(s)\n",i-1);
    }
    return 0;
}
