#include "stdio.h"
int a[10001]={0};
int min(int x,int y)
{
if(x>y)return y;
else return x;
}
int main()
{
int n,i,j;
    a[1]=1;
    for(i=1;i<=10000;i++)
    {
    a[i]=i;
    for(j=1;j*j<=i;j++)
    {
    a[i]=min(a[i],a[j]+a[i-j]);
    if(i%j==0)a[i]=min(a[i],a[j]+a[i/j]);
    }
    }
    while(scanf("%d",&n)==1)
    printf("%d\n",a[n]);
}
