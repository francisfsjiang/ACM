#include<stdio.h>
int step[1000][3];
int date[1000][1000][2];
int qh,qe;
int n;
main()
{
      freopen("gs.in","rt+",stdin);
      freopen("gs.out","wt+",stdout);
      int i,j;
      int search(int c);
      int p(int a);
      memset(step,0,sizeof(step));
      memset(date,0,sizeof(date));
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
      //for(i=0;i<=n+1;i++)
      //{
      //                for(j=0;j<=n+1;j++)
      //                {
      //                                printf("%d ",date[i][j][0]);
      //                }
      //                printf("\n");
      //}
      step[0][0]=1;//x
      step[0][1]=1;//y
      step[0][2]=0;
      date[1][1][1]=1;
      search(0);
      return(0);
      }
      
      int search(int c)
      {
          int x,y,i,j,k;
          //printf("------------------\n");
          //printf("search(%d)\n",c);
          x=step[c][0];
          y=step[c][1];
          if(date[x][y][0]==3)p(c);
          else
          {
              if(date[x][y-1][1]!=1&&date[x][y-1][0]!=1)
              {
                                    step[qe+1][0]=x;
                                    step[qe+1][1]=y-1;
                                    step[qe+1][2]=c;
                                    date[x][y-1][1]=1;
                                    qe++;
              }
              if(date[x][y+1][1]!=1&&date[x][y+1][0]!=1)
              {
                                    step[qe+1][0]=x;
                                    step[qe+1][1]=y+1;
                                    step[qe+1][2]=c;
                                    date[x][y+1][1]=1;
                                    qe++;
              }
              if(date[x-1][y][1]!=1&&date[x-1][y][0]!=1)
              {
                                    step[qe+1][0]=x-1;
                                    step[qe+1][1]=y;
                                    step[qe+1][2]=c;
                                    date[x-1][y][1]=1;
                                    qe++;
              }
              if(date[x+1][y][1]!=1&&date[x+1][y][0]!=1)              
              {
                                    step[qe+1][0]=x+1;
                                    step[qe+1][1]=y;
                                    step[qe+1][2]=c;
                                    date[x+1][y][1]=1;
                                    qe++;
              }
              qh++;
              //printf("qh=%d\n",qh);
              //printf("qe=%d\n",qe);
              //printf("d=%d\n",d);
              //for(j=0;j<3;j++)
              //{
              //                  for(i=0;i<=qe;i++)
              //                  {
              //                                    printf("%d ",step[i][j]);
              //                  }
              //                  printf("\n");
              //}
              //printf("------------------\n");
              search(c+1);
          }
      }
      int p(int a)
      {
          int i;
          i=a;
          for(;;)
          {
                 printf("(%d,%d)\n",step[i][0],step[i][1]);
                 if(step[i][2]==0)break;
                 i=step[i][2];
          }
          printf("(1,1)\n");
      }
          
