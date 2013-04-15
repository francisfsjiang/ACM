#include<stdio.h>
const int size=4000;
main()
{    
     freopen("for.in","rt+",stdin);    
     freopen("for.out","wt+",stdout);
     unsigned long t1[size],t2[size];
     unsigned long n,n1,n2,m,i,j;
     memset(t1,0,sizeof(t1)); 
     memset(t1,0,sizeof(t1));
     scanf("%d",&n); 
     printf("%d\n",n);
     
     
     for(m=1;m<=n;m++)
     {
     scanf("%d",&n1);
     scanf("%d",&n2);
     t1[1]=1;
     for(i=1;i<=n2+1;i++)
     {
                     t2[1]=1;
                     t2[i]=1;
                     for(j=2;j<i;j++)
                     {
                                      t2[j]=(t1[j-1]+t1[j])%1007;
                     }
                     for(j=1;j<=i;j++)t1[j]=t2[j];
     }
     printf("%d\n",t1[n1+1]);
     }
     
     
     return(0);
}
