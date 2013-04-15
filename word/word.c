#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
      freopen("word.in","rt+",stdin);
      freopen("word.out","wt+",stdout);
      int i,j,l,maxn,minn,d=0,n,abc[200]={0};
      char s[102];
      float w;
      scanf("%s",s);
      l=strlen(s);
      for(i=0;i<l;i++)
      {
                      abc[s[i]]++;
      }
      maxn=abc[97];
      minn=1000;
      for(i=97;i<123;i++)
      {
                         if(abc[i]!=0&&abc[i]>maxn)maxn=abc[i];
                         if(abc[i]!=0&&abc[i]<minn)minn=abc[i];
      }
      n=maxn-minn;
      if(n==0) printf("No Answer\n0");
      else if(n==1) printf("No Answer\n0");
      else if(n==2) printf("Lucky Word\n2");
      else
      {
          w=sqrt(n);
          for(i=2;d==0&&i<=w;i++)
          {
                             if(n%i==0)d=1;
          }
          if(d==0)
          {
              printf("Lucky Word\n%d",n);
          }
          else printf("No Answer\n0");
      }
      return(0);
}
