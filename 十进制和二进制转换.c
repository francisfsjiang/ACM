#include<stdio.h>
#include<math.h>
main()
{
int a,b,c,d,decide;                                      //10to2���ݶ��� 
int x[9999];                                      //10to2���ݶ��� 
int m,n,v,p,r=0,s,t;                                         //2to10���ݶ��� 
int y[9999];                                         //2to10���ݶ��� 
printf("������'10'��'2'��'10'��ʾ10����ת2���ƣ�'2'��ʾ2����ת10����\n");
scanf("%d",&decide);
if(decide==10)                                         //10to2
 {
 printf("������һ��10������,���»س�.\n");
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
 printf("������һ��2��������ÿ����һλ�����»س���������ɺ�������2��β�������»س�.\n");
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
