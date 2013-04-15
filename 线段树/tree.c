#include<stdio.h>
int treem[10000],treex[10000],treey[10000],c[10000]={0};
main()
{
      freopen("tree.in","rt+",stdin);
      freopen("tree.out","w+",stdout);
      int build(int a,int x,int y);
      int insert(int a,int x,int y);
      int count(int a,int x,int y);
      int l,m,i,x,y;
      scanf("%d%d",&l,&m);
      build(1,1,l);
      for(i=0;i<m;i++)
      {
                      scanf("%d%d",&x,&y);
                      insert(1,x,y);
      }
      for(i=1;i<=20;i++)printf("%2d ",i);
      printf("\n");
      for(i=1;i<=20;i++)printf("%2d ",treex[i]);
      printf("\n");
      for(i=1;i<=20;i++)printf("%2d ",treey[i]);
      printf("\n");
      for(i=1;i<=20;i++)printf("%2d ",c[i]);
      printf("\n");
      return 0;
}


int count(int a,int x,int y)
{
    if(c[a]==1)return y-x;
    if(x<treem[a])
    {
                  if(y<=treem[a])
                  {
                                 return count(2*a,x,y);
                  }
                  else
                  {
                      return count(2*a,x,treem[a]);
                      return count(2*a+1,treem[a],y);
                  }
    }
    else
    {
        return count(2*a+1,x,y);
    }
}
int build(int a,int x,int y)
{
    int t=y-x;
    treex[a]=x;
    treey[a]=y;
    if(t==1)return;
    if(t%2==0)
    {
              treem[a]=x+t/2;
              build(2*a,x,x+t/2);
              build(2*a+1,x+t/2,y);
    }
    else
    {
        treem[a]=x+(t+1)/2;
        build(2*a,x,x+(t+1)/2);
        build(2*a+1,x+(t+1)/2,y);
    }
}

int insert(int a,int x,int y)
{
    if(c[a]==1)return;
    if(x==treex[a]&&y==treey[a])
    {
                                c[a]=1;
                                return;
    }
    if(x<treem[a])
    {
                  if(y<=treem[a])
                  {
                                 insert(2*a,x,y);
                  }
                  else
                  {
                      insert(2*a,x,treem[a]);
                      insert(2*a+1,treem[a],y);
                  }
    }
    else
    {
        insert(2*a+1,x,y);
    }
}
