#include<stdio.h>
main()
{
int n;
unsigned long a,b,c;
scanf("%d",&n);
for(a=1;a<=n;a++)
 for(b=1;b<=n;b++)
     {
      if(a!=b&&a<b)printf("%ld,%ld\n",a,b);
     }
getchar();
getchar();
}
