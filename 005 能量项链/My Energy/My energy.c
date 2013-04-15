#include<stdio.h>
main()
{
      int i,j,k,dat,max,n;
      int date[1000],dp[100][100];
      freopen("energy.in","rt+",stdin);
      freopen("energy.out","wt+",stdout);
      scanf("%d",&n);
      for(i=0;i<n;i++)scanf("%d",&date[i]);
      for(i=2;i<=n;i++)//珠子数 
      {
                      for(j=0;j<n;j++)//起始珠子数 
                      {
                                       max=0;
                                       for(k=0;k<i-1;k++)//分段 
                                       {
                                                        dat=dp[k+1][j]+dp[i-k-1][(k+j+1)%n]+date[j]*date[(j+k+1)%n]*date[(i+j)%n];
                                                        //printf("dat=dp[%d][%d]+dp[%d][%d]+date[%d]*date[%d]*date[%d]\n",k+1,j,i-k-1,(k+j+1)%n,j,(j+k+1)%n,(i+j)%n);
                                                        //printf("%d=%d+%d+%d*%d*%d\n",dat,dp[k+1][j],dp[i-k-1][(k+j+1)%n],date[j],date[(j+k+1)%n],date[(i+j)%n]);
                                                        //printf("------------------------\n");
                                                        if(dat>max)max=dat;
                                       }
                                       dp[i][j]=max;
                                       //printf("dp[%d][%d]=%d\n***************************\n",j,i,max);
                      }
      }
      //for(k=0;k<n;k++)printf("%3d ",date[k]);
      //printf("\n");
      //for(k=2;k<=n;k++)
      //{
      //                 for(i=0;i<=n;i++)printf("%3d ",dp[k][i]);
      //                 printf("\n");
      //}
      max=0;
      for(i=0;i<=n;i++)if(dp[n][i]>max)max=dp[n][i];
      printf("%d",max);
      return(0);
}
