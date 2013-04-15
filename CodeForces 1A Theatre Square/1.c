#include<stdio.h>
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
   long long  n,m,a,i,x,y,rex,rey;
    long long result;
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    x=n%a;
    y=m%a;
    if(x==0)rex=n/a;
    else rex=(n-x)/a+1;
    if(y==0)rey=m/a;
    else rey=(m-x)/a+1;
    result=rex*rey;
    printf("%I64d\n",result);
    return 0;
}
