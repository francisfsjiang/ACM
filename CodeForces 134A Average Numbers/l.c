#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,sum=0,i;
    int data[250000];
    int sign[250000]={0},signn=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
        sum+=data[i];
    }
    for(i=1;i<=n;i++)
    {
        if(data[i]*n==sum)
        {
            signn++;
            sign[i]++;
        }
    }
    printf("%d\n",signn);
    for(i=1;i<=n;i++)if(sign[i]>0)printf("%d ",i);
    return 0;
}
