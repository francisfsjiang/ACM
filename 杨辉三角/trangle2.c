#include<stdio.h>
const int size=4000;
main()
{    
     freopen("trangle2.in","rt+",stdin);    
     freopen("trangle2.out","wt+",stdout);
     unsigned long t1[size],t2[size];
     unsigned long n,i,j;
     memset(t1,0,sizeof(t1)); 
     memset(t1,0,sizeof(t1));
     scanf("%d",&n); 
     printf("%d\n",n);
     t1[1]=1;
     for(i=1;i<=n;i++)
     {
                     t2[1]=1;
                     t2[i]=1;
                     for(j=2;j<i;j++)
                     {
                                      t2[j]=t1[j-1]+t1[j];
                     }
                     for(j=1;j<=i;j++)t1[j]=t2[j];
     }
     for(i=1;i<=n;i++)printf("%d ",t1[i]);

     return(0);
}
                                      
                                       
