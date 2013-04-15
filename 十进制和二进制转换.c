#include<stdio.h>
#include<math.h>
main()
{
int a,b,c,d,decide;                                      //10to2数据定义 
int x[9999];                                      //10to2数据定义 
int m,n,v,p,r=0,s,t;                                         //2to10数据定义 
int y[9999];                                         //2to10数据定义 
printf("请输入'10'或'2'，'10'表示10进制转2进制，'2'表示2进制转10进制\n");
scanf("%d",&decide);
if(decide==10)                                         //10to2
 {
 printf("请输入一个10进制数,按下回车.\n");
 scanf("%d",&a);
 if(a==0) printf("0");
 else if(a==1) printf("1");
 else if (a==2) printf("10");
 else
  {
  for(c=0;;c++)
   {
   b=a%2;
   x[c]=b;
   a=(a-b)/2;
   if(a==1) 
    {
    x[c+1]=1;
    break;
    }
   }
  for(d=c+1;d>=0;d--)
   printf("%d",x[d]);
  }
 }


if(decide==2)                                         //2to10
 {
 printf("请输入一个2进制数，每输入一位，按下回车，输入完成后再输入2结尾，并按下回车.\n");
 for(m=0;m<=99999;m++)
  {
  scanf("%d",&s);
  if(s==2) break;
  else y[m]=s;
  }
if(y[0]==0) printf("0");
else if(y[0]==1) printf("1");
else if(y[0]==1&&y[1]==0) printf("2");
else
  {
  for(t=m,n=0;t>=0;n++,t--)
   {
   v=pow(2,n-1);
   p=v*y[t];
   r=r+p;
   }
  printf("%d",r);
  }
 }
getchar();
getchar();
}
