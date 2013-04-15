#include<stdio.h>
main()
{
      freopen("hotel.in","r",stdin);
      freopen("hotel.out","w",stdout);
      int i,j,k,p,m,n,data[200003][2];
      unsigned long sum=0,temp;
      scanf("%d%d%d",&n,&m,&p);
      for(i=0;i<n;i++)scanf("%d%d",&data[i][0],&data[i][1]);
      for(i=0;i<n-1;i++)
      {
                        for(j=n-1;j>i;j--)
                        {
                                          if(data[i][0]==data[j][0])
                                          {
                                          temp=sum;
                                          for(k=i;k<=j;k++)
                                          {
                                                           
                                                           if(data[k][1]<=p)
                                                           {
                                                                            sum++;
                                                                            break;
                                                           }
                                          }
                                          if(temp==sum)break;
                                          }
                        }
      }
      printf("%ld",sum);
      return(0);
}
