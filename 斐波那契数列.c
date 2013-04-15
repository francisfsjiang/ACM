#include<stdio.h>
main()
{
unsigned long a,b,c,m,n;
printf("2<=n<=46\n");
scanf("%d",&n);
printf("1\n");
printf("1\n");
for(a=1,b=1,m=2;m<n;a=b,b=c,m++)
 {
  c=a+b;
  printf("%ld\n",c);
 }
getchar();
getchar();
}
