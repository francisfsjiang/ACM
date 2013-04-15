#include<stdio.h>
main()
{
      freopen("distance.in","rt+",stdin);
      freopen("distance.out","wt+",stdout);
      int g[100][100],dist[100],used[100]={0};
      int i,j,k,n,edge,x,y,z,min,minn;
      scanf("%d%d",&n,&edge);
      for(i=0;i<edge;i++)
      {
                         scanf("%d%d%d",&x,&y,&z);
                         g[x][y]=z;
      }
      for(i=1;i<=n;i++)
      {
                       if(g[1][i]!=0)dist[i]=g[1][i];
                       else dist[i]=10000;
      }
      used[1]=1;
      for(i=1;i<=n-1;i++)//寻点 
      {
                       min=10000;
                       for(j=2;j<=n;j++)//找最短的 
                       {
                                        if(dist[j]<min&&used[j]==0)
                                        {
                                                        min=dist[j];
                                                        minn=j;
                                        }
                       }
                       printf("%d %d\n",min,minn);
                       used[minn]=1;
                       for(j=1;j<=n;j++)//修改dist值 
                       {
                                        if(g[minn][j]!=0&&used[j]==0)
                                        {
                                                                     if(g[1][j]==0)
                                                                     {
                                                                                   dist[j]=dist[minn]+g[minn][j];
                                                                     }
                                                                     else
                                                                     {
                                                                         if(g[1][j]<=g[minn][j]+dist[minn])
                                                                         {
                                                                                            dist[j]=g[1][j];
                                                                         }
                                                                         else dist[j]=g[minn][j]+dist[minn];
                                                                     }
                                                                     printf("dist[%d]=%d\n",j,dist[j]);
                                        }
                       }
      }
     for(j=1;j<=n;j++) printf("%d ",dist[j]);
     printf("\n");
     return(0);
}
