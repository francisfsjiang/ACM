#include<stdio.h>
#include<math.h>
int main()
{
freopen("prime.out","w",stdout);
unsigned long prime(unsigned long x);
unsigned long a,b,n,p,sign;
a=2;
b=10000;
sign=0;
for(n=1;a<=b;a++)
 {
  p=prime(a);
  if(p==1)
   {
    printf("%ld",a);
    printf(",");
    sign++;
    n++;
   }
  if(n==11)
   {
    n=1;
    printf("\n");
   }
 }
 printf("\n%d\n",sign);
//getchar();
//getchar();
return 0;
}

unsigned long prime(unsigned long x)
{
    unsigned long u,m;
    long double s;
    s=sqrt(x);
    if(x==0) m=0;
    else if(x==1) m=0;
    else if(x==2) m=1;
    else if(x==3) m=1;
    else
     {
      for(u=2;u<=s;u++)
       {
         if(x%u==0)
          {
          m=0;
          break;
          }
         else
          m=1;
       }
     }
    return(m);
}

