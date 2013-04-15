#include<stdio.h>
main()
{
int i,j;
unsigned long n=1;
scanf("%d",&j);
for(i=0;i<j;i++)n=2*n;
n=n-1;
n=n*2;
printf("%ld",n);
return(0);
}
