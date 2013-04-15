#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    float sum,n;
    int i;
    for(i=1;i<=12;i++)
    {
        scanf("%f",&n);
        sum+=n;
    }
    printf("$%.2f\n",sum/12);
return 0;
}
