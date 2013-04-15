#include<stdio.h>
#include<math.h>
main()
{
      freopen("Struct.in","rt+",stdin);
      freopen("Struct.out","wt+",stdout);
      int i,j,m,n,date[10000],a=1,b=1,w=0;
      int s(int x,int y);
      scanf("%d%d",&n,&m);
      date[1]=1;
      for(;;)
      {
           date[b+1]=s(n,a);
           for(i=1;i<=b;i++)
           {
                            date[i+b+1]=date[b+1]+date[i];
                            if(i+b+1==m)
                            {
                                        w=1;
                                        break;
                            }
           }
           if(w==1)break;
           a++;
           b=2*b+1;
      }
      printf("%d",date[m]);
      return(0);
}
           
int s(int x,int y)
{
    int i,sum=1;
    for(i=0;i<y;i++)sum=sum*x;
    return(sum);
}
