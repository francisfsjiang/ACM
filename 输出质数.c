#include<stdio.h>
#include<math.h>
main()
{
unsigned long a,b,c,s,n;
int w;
printf("Please press a number between 0 and 4294967295.\n");
scanf("%ld",&n);
for(a=1;a<=n;a++)
{
 s=sqrt(a);
 for(c=2;c<=s;c++)
  {
    if(a%c==0)
     {
      w=0;
      break;
     }
    else 
     w=1;
   }
 if (w==1)
    printf("%ld\n",a);
}
getchar();
getchar();
}


 

