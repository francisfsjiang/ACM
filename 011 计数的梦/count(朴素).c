#include<stdio.h>
#include<string.h>
main()
{
      freopen("count.in","rt+",stdin);
      freopen("count.out","wt+",stdout);
      int i,j,k,l1=0,l2=0,temp,d=0;
      char a[1000],b[1000];
      int sum[10];
      scanf("%s%s",a,b);
      l1=strlen(a);
      l2=strlen(b);
      printf("%d\n%d\n",l1,l2);
      printf("%s\n%s\n",a,b);
      for(i=0;i<l1;i++)a[i]-=48;
      for(i=0;i<l2;i++)b[i]-=48;
      for(i=0;i<l1/2;i++){temp=a[i];a[i]=a[l1-i-1];a[l1-i-1]=temp;}
      for(i=0;i<l2/2;i++){temp=b[i];b[i]=b[l2-i-1];b[l2-i-1]=temp;}
      printf("%d %d %d\n",a[0],a[1],a[2]);
      printf("%s\n%s\n",a,b);
      for(;;)
      {
             for(i=0;i<l1;i++)sum[a[i]]++;//记录
             a[0]++;
             for(i=0;i<l1;i++)//整理
             {
                                     if(a[i]!=10)break;
                                     else
                                    {
                                         a[i]==0;
                                         if(a[i+1]==0)
                                         {
                                                      l1++;
                                                      a[i+1]++;
                                                      break;
                                         }
                                         else a[i+1]++;
                                     }
             }
             //开始了， 
      }
      printf("%s\n%s\n",a,b);
      return(0);
}
      
