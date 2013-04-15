#include<stdio.h>
int dist[10][10][10]={1000};
main()
{
      freopen("dist.in","rt+",stdin);
      freopen("dist.out","wt+",stdout);
      int i,j,n,x,y,a,edge,date,min,k;
      scanf("%d%d",&n,&edge);
      for(i=0;i<edge;i++)
      {
                         scanf("%d%d",&x,&y);
                         scanf("%d",&dist[x][y][1]);
      }
      for(i=1;i<=n;i++)for(a=1;a<=n-1;a++)for(j=1;j<=n;j++)if(i!=j&&dist[i][j][a]==0)dist[i][j][a]=1000;
      for(i=1;i<=n;i++)
      {
                       for(a=1;a<=n-1;a++)
                       {
                                          for(j=1;j<=n;j++)
                                          {
                                                           printf("%4d ",dist[i][j][a]);
                                          }
                                          printf("||");
                       }
                       printf("\n");
      }
      for(a=2;a<=n-1;a++)
      {
                         for(i=1;i<=n;i++)
                         {
                                          for(j=1;j<=n;j++)
                                          {
                                                           min=10000;
                                                           for(k=1;k<=n;k++)
                                                           {
                                                                            date=dist[i][k][a-1]+dist[k][j][1];
                                                                            if(date<min)min=date;
                                                           }
                                                           dist[i][j][a]=min;
                                          }
                         }
      }
      for(i=1;i<=n;i++)
      {
                       for(a=1;a<=n-1;a++)
                       {
                                          for(j=1;j<=n;j++)
                                          {
                                                           printf("%4d ",dist[i][j][a]);
                                          }
                                          printf("||");
                       }
                       printf("\n");
      }
      
      for(i=1;i<=n;i++)
      {
                       for(j=1;j<=n;j++)
                       {
                                        printf("%3d ",dist[i][j][n-1]);
                       }
                       printf("\n");
      }
      return(0);
}
                                                                            
