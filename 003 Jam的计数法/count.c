#include<stdio.h>
main()
{
      freopen("count.in","rt+",stdin);
      freopen("count.out","wt+",stdout);
      char date[100000],date2[100000];
      int s1,s2,n,i,j,k,tmp,w,sum=0;
      scanf("%d %d %d",&s1,&s2,&n);
      scanf("%s",date);
      for(i=0;sum<5;i++)
      {
                    w=0;
                    date[n-1]++;
                    tmp=0;                   
                   for(j=n-1;j>0;j--)
                   {
                                      if(date[j]>(s2+96))
                                      {
                                                          date[j]=s1+96+j;
                                                          date[j-1]++;
                                      }
                   }
                   for(k=0;k<n-1;k++)
                   {
                                     if(date[k]>=date[k+1])
                                     {
                                                           w=1;
                                                           break;
                                     }
                   }
                   if(date[0]>(s2-s1-n+3+96))break;
                   else if(w!=1) 
                   {
                        printf("%s\n",date);
                        sum++;
                        strcpy(date2,date);
                   }
      }
      if(sum<4)
      {
               for(i=0;i<(5-sum);i++)printf("%s\n",date2);
      }
}
