#include <stdio.h>
#include <string.h>
struct men
{
    char name[20];
}men[12];

main ()
{
     freopen ("input.txt","r",stdin);
     freopen ("out.out","w",stdout);
     int i,n,sum[15]={0},money,a,j,k,c,d,w,x;
     int t;
     char temp[15];
     for(;scanf("%d",&n)!=-1;)
     {
     for(i=0;i<=n;i++)sum[i]=0;
     for(i=0;i<n;i++)scanf("%s",men[i].name);
     for(i=0;i<n;i++)
     {
                     scanf("%s%d%d",temp,&money,&a);
                     for(k=0;k<n;k++)
                     {
                                     w=strcmp(temp,men[k].name);
                                     if(w==0)
                                     {
                                             break;
                                     }
                     }
                     if(a==0)continue;
                     else d=money/a;
                     for(j=0;j<a;j++)
                     {
                                     scanf("%s",temp);
                                     for(c=0;c<n;c++)
                                     {
                                                     w=strcmp(temp,men[c].name);
                                                     if(w==0)
                                                     {
                                                            sum[c]+=d;
                                                            sum[k]-=d;
                                                            break;
                                                     }
                                     }
                     }
     }
     for(i=0;i<n;i++){printf("%s %d\n",men[i].name,sum[i]);}
     printf("\n");
     }
     return 0;
}
