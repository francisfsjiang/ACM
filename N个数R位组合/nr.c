#include<stdio.h>
int n,r;
int temp[10000]={0},date[10000]={0};
main()
{
      int search(int x,int y);
      int i;
      freopen("nr.in","rt+",stdin);
      freopen("nr.out","wt+",stdout);
      scanf("%d%d",&n,&r);
      search(n,r);
      return(0);
}

int search(int x,int y)
{
    int i;
    if(y>=1)
    {
    for(i=1;i<=n;i++)
    {
                     if(date[i]==0)
                     {
                                   temp[r-y+1]=i;
                                   date[i]=1;
                                   search(x-1,y-1);
                                   date[i]=0;
                     }
    }
    }
    else
    {
        for(i=1;i<=r;i++)printf("%d ",temp[i]);
        printf("\n");
    }
}
