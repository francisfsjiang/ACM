#include<stdio.h>
int fa[5005]={0};
main()
{
      freopen("family.in","r",stdin);
      freopen("family.out","w",stdout);
      int i,j,n,m,p,a,b;
      int father(int x);
      scanf("%d%d%d",&n,&m,&p);
      for(i=0;i<m;i++)
      {
                      scanf("%d%d",&a,&b);
                      if(fa[a]==0)
                      {
                                  fa[a]=father(b);
                      }
                      else
                      {
                          if(fa[b]==0)fa[b]=father(a);
                          else fa[father(b)]=father(a);
                      }
                      //for(j=1;j<=n;j++)printf("%d ",fa[j]);
                      //printf("\n");
                      
      }
      
      //for(i=1;i<=n;i++)printf("%d ",fa[i]);
      for(i=0;i<p;i++)
      {
                      scanf("%d%d",&a,&b);
                      if(father(a)==father(b))printf("Yes\n");
                      else printf("No\n");
      }
      return(0);
}

int father(int x)
{
    if(fa[x]==0)
    {
                fa[x]=x;
                return(x);
    }
    else if(fa[x]==x)
    {
         return(x);
    }
    else
    {
        fa[x]=father(fa[x]);
        return(fa[x]);
    }
}
