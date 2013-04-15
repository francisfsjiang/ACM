#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    unsigned long int x,y,m,n,l,temp;
    scanf("%ld%ld%ld%ld%ld",&x,&y,&m,&n,&l);
    if(y<x)
    {
        temp=x;
        x=y;
        t=temp;
        temp=m;
        m=n;
        n=temp;
    }
    if(m==n&&x!=y)printf("Impossible\n");
    else if(m<n)
    {
        if(l%(n-m)==0)
