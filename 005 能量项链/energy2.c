#include<stdio.h>
#include<string.h>
const int SIZE=105;
int main()
{
     freopen("energy.in","r",stdin);
     freopen("energy.out","w",stdout);
     int n,dat[SIZE],i,j,k,dp[SIZE][SIZE];
     scanf ("%d",&n);
     for (i=0;i<n;i++)
     scanf ("%d",&dat[i]);
     memset(dp,0,sizeof(dp));
     for (j=2;j<=n;j++)
     {
         for (i=0;i<n;i++)
         {
             int max=0;
             for (k=1;k<j;k++)
                {
                 int tmp=dp[i][k]+dp[(i+k)%n][j-k]+dat[i]*dat[(i+k)%n]*dat[(i+j)%n];
                 if (tmp>max)
                 max=tmp;
                 /*printf("j=%d\n",j);
                 printf("i=%d\n",i);
                 printf("k=%d\n",k);
                 printf("tmp=%d\n",tmp);
                 printf("max=%d\n",max);
                 printf("tmp=dp[%d][%d]+dp[%d][%d]+dat[%d]*dat[%d]*dat[%d]\n",i,k,(i+k)%n,j-k,i,(i+k)%n,(i+j)%n);
                 printf("------------------------------------\n");*/
                 }
                 dp[i][j]=max;
                 /*printf("dp[%d][%d]=max=%d\n",i,j,max);
                 printf("------------------------------------\n");    */
          }
     }
     /*for(k=0;k<n;k++)printf("%3d ",dat[k]);
     printf("\n");
     for(k=2;k<=n;k++)
     {
                      for(i=0;i<=n;i++)printf("%3d ",dp[i][k]);
                      printf("\n");
     }*/

     int max=0;
     for (i=0;i<n;i++)
     if (dp[i][n]>max)
     max=dp[i][n];
     printf("%d\n",max);
     return 0;
}
