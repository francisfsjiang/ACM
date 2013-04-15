#include<stdio.h>
main()
{
      int i,a[10],n=0,h;
      for(i=0;i<10;i++)
      {
                       scanf("%d",&a[i]);
      }
      scanf("%d",&h);
      for(i=0;i<10;i++)
      {
                       if(h+30>=a[i])n++;
      }
      printf("%d",n);
      return 0;
}
