#include<stdio.h>
int step[1000][2];
int date[10000][10000][2];
main()
{
      freopen("ss.in","rt+",stdin);
      freopen("ss.out","wt+",stdout);
      int n,i,j;
      int search(int x,int y,int z);
      int pr(int c);
      memset(step,0,sizeof(step));
      scanf("%d",&n);
      for(i=0;i<=n+1;i++)
      {
                      for(j=0;j<=n+1;j++)
                      {
                                      date[i][j][0]=1;
                      }
      }
      for(i=1;i<=n;i++)
      {
                      for(j=1;j<=n;j++)
                      {
                                      scanf("%d",&date[i][j][0]);
                      }
      }
      for(i=0;i<=n+1;i++)
      {
                      for(j=0;j<=n+1;j++)
                      {
                                      printf("%d ",date[i][j][0]);
                      }
                      printf("\n");
      }
      search(1,1,1);
      return(0);
}

pr(int c)
{
       int a,b;
       for(a=0;a<2;a++)
       {
                       for(b=1;b<=c;b++)
                       {
                                       printf("%d ",step[b][a]);
                       }
                       printf("\n");
       }
       printf("\n");
}

search(int x,int y,int z)
{
           //printf("--------------\nx=%d\ny=%d\nz=%d\n-------------\n",x,y,z);
           step[z][0]=x;
           step[z][1]=y;
           date[x][y][1]=1;
           if(date[x][y][0]==3)pr(z);
           else
           {
           if(date[x-1][y][0]!=1&&date[x-1][y][1]!=1)search(x-1,y,z+1);
           if(date[x+1][y][0]!=1&&date[x+1][y][1]!=1)search(x+1,y,z+1);
           if(date[x][y-1][0]!=1&&date[x][y-1][1]!=1)search(x,y-1,z+1);
           if(date[x][y+1][0]!=1&&date[x][y+1][1]!=1)search(x,y+1,z+1);
           }
}
           
