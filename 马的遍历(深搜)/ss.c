#include<stdio.h>
int n,sum=0,e;
int date[100][100],step[100][2];
int h[8]={-1,-2,-2,-1,1,2,2,1};
int s[8]={-2,-1,1,2,2,1,-1,-2};
main()
{
      freopen("ss.in","rt+",stdin);
      freopen("ss.out","wt+",stdout);
      int i,j;
      int search(int x,int y);
      memset(date,0,sizeof(date));
      memset(step,0,sizeof(step));
      scanf("%d",&n);
      printf("%d\n",n);
      e=n*n;
      //for(i=1;i<=n;i++)
      //{
      //                 for(j=1;j<=n;j++)
      //                 {
      //                 printf("****************************************\n");
      //                 memset(date,0,sizeof(date));
      //                 sum=0;
                       search(1,1);
      //                 }
      //}
      return(0);
}

int search(int x,int y)
{
    int i,j,a,b,d=0;
    if(date[x][y]==0&&sum<e)
    {
                               //调试 
                               //printf("第%d步\n",sum);
                               //printf("search(%d,%d)\n",x,y);
                               //for(j=1;j<=n;j++)
                               //{
                               //                 for(i=1;i<=n;i++)printf("%d ",date[j][i]);
                               //                 printf("\n");
                               //}
                               //printf("\n");
                               //for(j=0;j<=1;j++)
                               //{
                               //                 for(i=1;i<=e;i++)printf("%d ",step[i][j]);
                               //                 printf("\n");
                               //}
                               //printf("\n");
                               //调试 
                               date[x][y]=1;
                               sum++;
                               step[sum][0]=x;
                               step[sum][1]=y;
                               for(i=0;i<8;i++)
                               {
                                               a=x+h[i];
                                               b=y+s[i];
                                               if(a>=1&&a<=n&&b>=1&&b<=n&&date[a][b]==0)
                                               {
                                                                                        search(a,b);
                                                                                        //d=1;
                                               }
                               }
                               //if(d==0)
                               //{
                                //printf("回溯\n");
                                date[x][y]=0;
                                sum--;
                                step[sum+1][0]=0;
                                step[sum+1][1]=0;
                               //}
    }
    else if(sum==e)
    {
         for(a=e;a>=1;a--)
         {
              printf("(%d,%d)\n",step[a][0],step[a][1]);
         }
    }
}
                        
    


