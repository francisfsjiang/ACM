#include <stdio.h>
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
main ()
{
     freopen ("friday.in","r",stdin);
     freopen ("out.out","w",stdout);
     int n,i,j,k,p,week=1,s[8]={0};
     //for(;scanf("%d",&n)!=-1;)
     {
     for(i=0;i<=7;i++)s[i]=0;
     week=1;
     for(i=1900;i<1900+n;i++)
     {
                     if(i%100==0)
                     {
                                 if(i%400==0)m[2]=29;
                                 else m[2]=28;
                     }
                     else
                     {
                         if(i%4==0)m[2]=29;
                         else m[2]=28;
                     }
                     for(j=1;j<=12;j++)
                     {
                                       for(k=1;k<=m[j];k++)
                                       {
                                                           if(k==13)s[week]++;
                                                           week++;
                                                           if(week==8)week=1;
                                       }
                     }
     }
     printf("%d %d",s[6],s[7]);
     for(p=1;p<=5;p++)printf(" %d",s[p]);
     printf("\n");
     }
     return 0;
}
