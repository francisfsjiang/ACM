#include<stdio.h>
int W[10000][2];
main()
{
      freopen("photo.in","rt+",stdin);
      freopen("photo.out","wt+",stdout);
      int n,k,i,j,D[10000],E[10],sum=0;
      int quicksort(int s,int t);
      scanf("%d%d",&n,&k);
      for(i=0;i<10;i++)
      {
                       scanf("%d",&E[i]);
      }
      for(i=0;i<n;i++)
      {
                      W[i][0]=i+1;
                      scanf("%d",&W[i][1]);
      }
      for(i=0;i<2;i++)
      {
                      for(j=0;j<n;j++)
                      {
                                      printf("%d ",W[j][i]);
                      }
                      printf("\n");
      }
      quicksort(0,n-1);
      for(i=0;i<2;i++)
      {
                      for(j=0;j<n;j++)
                      {
                                      printf("%d ",W[j][i]);
                      }
                      printf("\n");
      }
      for(i=n-1;i>=0;i--)
      {
                         W[i][1]+=E[sum];
                         sum++;
                         if(sum==10)sum=0;
      }
      for(i=0;i<2;i++)
      {
                      for(j=0;j<n;j++)
                      {
                                      printf("%d ",W[j][i]);
                      }
                      printf("\n");
      }
      for(i=n-1;i>=n-k;i--)
      {
                         printf("%d ",W[i][0]);
      }
      quicksort(0,n-1);
      return(0);
}

int quicksort(int s,int t)
{
     int i,j,y,y2,temp,temp2,m,k;
     m=rand()%(t+1-s)+s;
     i=s-1;
     j=t+1;
     y=W[m][1];
     y2=W[m][0];
     for(;i<j;)
     {
                 for(i++;i<=t&&W[i][1]<y;i++);
                 for(j--;j>=0&&W[j][1]>y;j--);
                 if(i==m){j++;continue;}
                 if(j==m){i--;continue;}
                 if(i<j)
                 {
                        temp=W[i][1];
                        temp2=W[i][0];
                        W[i][1]=W[j][1];
                        W[i][0]=W[j][0];
                        W[j][1]=temp;
                        W[j][0]=temp2;
                 }
     }
     if(m<j)
     {
            W[m][1]=W[j][1];
            W[m][0]=W[j][0];
            W[j][1]=y;
            W[j][0]=y2;
     }
     else if(m>j)
     {
          W[m][1]=W[j+1][1];
          W[m][0]=W[j+1][0];
          W[j+1][1]=y;
          W[j+1][0]=y2;
     }
     if(s<j-1)quicksort(s,j-1);
     if(j+1<t)quicksort(j+1,t);
}
