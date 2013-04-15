#include <stdio.h>
main()
{
      int maxs[10];
      int s[10];
      int h,i,n,temp;
      
      scanf("%s",s);
      scanf("%d",n);
      for(h=0;h<10;h++)
       {
       for(i=0;i<10-h;i++)
        {
        if(s[i]>s[i+1])
         {
         temp=s[i+1];
         s[i+1]=s[i];
         s[i]=temp;
         }
        }
       }
       printf("%d",s[10-n]);
}
      
       
