#include<stdio.h>
const int size=500;
main()
{    
     freopen("trangle.in","rt+",stdin);    
     freopen("trangle.out","wt+",stdout);
     int t[size][size];
     int n,i,j;
     memset(t,0,sizeof(t)); 
     scanf("%d",&n); 
     //printf("%d\n",n);
     for(i=1;i<=n;i++)
     {
                     t[1][i]=1;
                     t[i][i]=1;
                     for(j=2;j<i;j++)
                     {
                                      t[j][i]=t[j-1][i-1]+t[j][i-1];
                     }
     }
     
     for(i=1;i<=n;i++)
     {
                      for(j=1;j<=i;j++)
                      {
                                        printf("%d ",t[j][i]);
                      }
                      printf("\n");
     }
     return(0);
}
                                      
                                       
