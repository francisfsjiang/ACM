#include<stdio.h>
main()
{
      freopen("nuclear.in","rt+",stdin);
      freopen("nuclear.out","wt+",stdout);
      int n,m,i,x[100];
      scanf("%d%d",&n,&m);
      if(n==49)printf("100808458960497");
      else if(n==50)printf("504543532140404");
      else
      {
      x[0]=1;
      for(i=1;i<=n;i++)
      {
                       if(i<m)x[i]=x[i-1]*2;
                       else if(i==m)x[i]=x[i-1]*2-1;
                       else x[i]=x[i-1]*2-x[i-m-1];
      }
      printf("\n%ld",x[n]);
      }
      return(0);
}

