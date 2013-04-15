#include<stdio.h>
main()
{
      freopen("count.in","rt+",stdin);
      freopen("count.out","wt+",stdout);
      char date[100000];
      int s1,s2,n,i,j,k,tmp,w;
      scanf("%d %d %d",&s1,&s2,&n);
      printf("s1=%d\ns2=%d\nn=%d\n",s1,s2,n);
      date[0]=s1+96;
      for(i=1;i<n;i++)date[i]=date[i-1]+1;
      printf("%s\n",date);
      printf("********************************************\n");
      for(i=0;1;i++)
      {
                    w=0;
                    //printf("********************************************\n");
                    date[n-1]++;
                    tmp=0;
                   //printf("date[n-1]=%d\n",date[n-1]);                   
                   for(j=n-1;j>0;j--)
                   {
                                      //printf("------------\n");
                                      if(date[j]>(s2+96))
                                      {
                                                          date[j]=s1+96;
                                                          date[j-1]++;
                                      }  
                                      //printf("------------\n");
                   }
                   for(k=0;k<n-1;k++)
                   {
                                     if(date[k]>=date[k+1])
                                     {
                                                           w=1;
                                                           break;
                                     }
                   }
                   //printf("w=%d\n",w);
                   //printf("date[0]=%d\n",date[0]);
                   if(date[0]>(s2-s1-n+3+96))break;
                   else if(w!=1) printf("%s\n",date);
      }
}
