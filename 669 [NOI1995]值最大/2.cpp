#include<stdio.h>
main()
{
freopen("in.in","r",stdin);
freopen("out.out","w",stdout);
int n,a=1,b=1,c;
scanf("%d",&n);
for(;;)
{
       c=a+b;
       if(c>n)
       {
               printf("%d %d",a,b);
               break;
       }
       a=b;
       b=c;
}
return(0);
}
