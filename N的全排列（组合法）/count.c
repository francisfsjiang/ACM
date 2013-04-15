#include<stdio.h>
int p=0,n,a[100],d[100];
main()
{
      freopen("count.in","rt+",stdin);
      freopen("count.out","wt+",stdout);
      int try(int x);
      int i;
      scanf("%d",&n);
      for(i=1;i<=n;i++)printf("%d ",d[i]);
      printf("\n");
      try(1);
      return(0);
}

int try(int x)
{
    int i;
    for(i=1;i<=n;i++)
    {
                    if(d[i]==0)
                    {
                               a[x]=i;
                               d[i]=1;
                    }
                    else continue;
                    if(x<n)try(x+1);
                    else
                    {
                        p++;
                        output();
                    }
                    d[a[x]]=0;
    }
}

int output()
{
    int i;
    printf("%d\n",p);
    for(i=1;i<=n;i++)printf("%d ",a[i]);
    printf("\n");
    for(i=1;i<=n;i++)printf("%d ",d[i]);
    printf("\n");
}
