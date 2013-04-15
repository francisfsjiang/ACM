#include<stdio.h>
int father[30001],before[30001],count[300001]={1};
main()
{
      FILE *in,*out;
      in=fopen("galax.in","r");
      out=fopen("galax.out","w+");
      int T,i,j,x,y;
      int root(int x);
      int before(int x);
      char c;
      fscnaf(in,"%d",&T);
      for(i=0;i<T;i++)
      {
                      fscanf(in,"%c%d%d",&c,&x,&y);
                      if(c==77)
                      {
                               father[father[x]]=3;
                               before[father[x]]=count[y];
                               count[y]+=count[father[x]];
                      }
                      else
                      {
                          if(father[x]==father[y])
                      }
      }
      return 0;
}

int root(int x)
{
    if(father[x]==father[father[x]])return father[x];
    else return root(father[x]);
}

int before(int x)
{
    if (father)
