#include<stdio.h>
main()
{
      int i,j,min=32767,max=0;
      int record[32768]={0};
      freopen("≤‚ ‘.out","wt+",stdout);
      for(i=0;i<1000000;i++)
      {
             record[rand()]++;
      }
      for(i=0;i<32768;i++)
      {
                          if(record[i]>max)max=record[i];
                          else if(record[i]<min)min=record[i];
      }
      printf("min=%d\nmax=%d\naverage=%d\n",min,max,1000000/32768);
}
