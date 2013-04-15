#include<stdio.h>
int n,s[100],p=0;
main()
{
      freopen("count.in","rt+",stdin);
      freopen("count.out","wt+",stdout);
      int i;
      int try(int x);
      int out();
      int swap(int x,int y);
      scanf("%d",&n);
      for(i=1;i<=n;i++)s[i]=i;
      try(1);
      printf("%d",p);
      return(0);
}

int try(int x)
{
    int i;
    if(x>n)out();
    else
    {
        for(i=x;i<=n;i++)
        {
                         swap(x,i);
                         try(x+1);
                         swap(x,i);
        }
    }
}

int out()
{
    int i;
    for(i=1;i<=n;i++)
    {
                    printf("%d ",s[i]);
    }
    printf("\n");
    p++;
}

int swap(int x,int y)
{
    int temp;
    temp=s[x];
    s[x]=s[y];
    s[y]=temp;
}
