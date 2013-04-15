#include<stdio.h>
#include<string.h>
main()
{
      freopen("sum.in","rt+",stdin);    
      freopen("sum.out","wt+",stdout);
      int l1,l2,l,i,m,n=0;
      char a[10000],b[10000];
      int x[10000],y[10000],r[10000]; 
      memset(x,0,sizeof(x));                    //以下三句将所有x\y\r中元素赋0 
      memset(y,0,sizeof(y));
      memset(r,0,sizeof(r));
      scanf("%s",a);
      scanf("%s",b);
      l1=strlen(a);
      l2=strlen(b);
      if(l1>=l2)l=l1;
      else l=l2;
      for(i=0;i<l1;i++)x[i]=a[l1-i-1]-48;
      //for(i=l1-1;i>=0;i--)printf("%d",x[i]);
      //printf("\n");
      for(i=0;i<l2;i++)y[i]=b[l2-i-1]-48;
      //for(i=l2-1;i>=0;i--)printf("%d",y[i]);
      //printf("\n");
      for(i=0;i<l;i++)r[i]=x[i]+y[i];
      for(i=0;i<l;i++)
      {
                         m=(n+r[i])%10;
                         n=(n+r[i]-m)/10;
                         r[i]=m;
      }
      if(n!=0)printf("%d",n);
      for(i=l-1;i>=0;i--)printf("%d",r[i]);
}
