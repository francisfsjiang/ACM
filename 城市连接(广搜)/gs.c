#include<stdio.h>
int visited[1000];
int date[1000][1000];
int step[1000][2];
int qh,qe;
int n;
main()
{
      freopen("gs.in","rt+",stdin);
      freopen("gs.out","wt+",stdout);
      int i,j,d=0,sum,k;
      int search(int b,int c);
      int p(int a);
      memset(visited,0,sizeof(visited));
      memset(step,0,sizeof(step));
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
                      for(j=1;j<=n;j++)
                      {
                                      scanf("%d",&date[i][j]);
                      }
      }
      step[1][0]=1;
      step[1][1]=0;
      visited[1]=1;
      qh=1;
      qe=1;
      for(;;)
      {
             sum=0;
             for(j=1;j<=n;j++)
             {
                              if(date[step[qh][0]][j]==1&&visited[j]!=1)
                              {
                                                                        visited[j]=1;
                                                                        step[qe+1+sum][0]=j;
                                                                        step[qe+1+sum][1]=qh;
                                                                        sum++;
                              }
                              if(step[qe][0]==8)
                              {
                                                p(qe);
                                                d=1;
                                                break;
                              }
             }
             if(d==1)break;
             qh++;
             qe=qe+sum;
      }
      return(0);
}

                                   
int p(int a)
{
    int i;
    i=a;
    for(;;)
    {
           printf("%d--",step[i][0]);
           i=step[i][1];
           if(i==1)break;
    }
    printf("1\n");
}
