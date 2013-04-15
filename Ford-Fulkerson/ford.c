#include<stdio.h>
int sum,g[100][100],n,path[100]={0},used[100]={0};
main()
{
      freopen("ford.in","rt+",stdin);
      freopen("ford.out","wt+",stdout);
      int search(int x);
      int i,j,a,b,edge;
      scanf("%d%d",&n,&edge);
      for(i=0;i<edge;i++)
      {
                      scanf("%d%d",&a,&b);
                      scanf("%d",&g[a][b]);
      }
      path[1]=1;
      used[1]=1;
      search(1);
      printf("%d",sum);
      return(0);
}

int search(int x)
{
    int i,d=1,min;
    for(i=1;i<=x;i++)printf("%d ",path[i]);
    printf("\n");
    if(path[x]==n)
    {
                  min=g[path[1]][path[2]];
            for(i=1;i<x;i++)
            {
                             if(g[path[i]][path[i+1]]<min)min=g[path[i]][path[i+1]];
            }
            for(i=1;i<x;i++)
            {
                             g[path[i]][path[i+1]]-=min;
            }
            sum+=min;
            printf("%d\n",min);
            return(0);
    }
    else
    {
    for(i=1;i<=n;i++)
    {
                     if(g[path[x]][i]!=0&&used[i]==0)
                     {
                                         path[x+1]=i;
                                         used[i]=1;
                                         search(x+1);
                                         used[i]=0;
                     }
    }
    }
}
    
