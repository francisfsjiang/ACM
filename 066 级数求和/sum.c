#include<stdio.h>
main()
{
      freopen("sum.out","w",stdout);
      int k,j=1,kk[17];
      double data=1;
      for(k=1;k<=15;)
      {
                        if(data<=k)
                        {
                                   j++;
                                   data+=(double)1/j;
                        }
                        else
                        {
                            kk[k]=j;
                            k++;
                        }
      }
      for(k=1;k<=15;k++)printf("%d,",kk[k]);
      return(0);
}
