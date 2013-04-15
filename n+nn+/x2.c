#include<stdio.h>
main()
{
      freopen("x2.in","rt+",stdin);    
      freopen("x2.out","wt+",stdout);
      int i,j,n;
      long date[500000];
      int fix(int a[],int x);
      scanf("%d",&n);
      printf("%d\n",n);
      memset(date,0,sizeof(date));
      date[0]=1*n;
      for(i=1;i<n;i++)
      {    
                      date[i]=date[i-1]-1;
      }
      //for(j=n-1;j>=0;j--)printf("%d",date[j]);
      //printf("\n");      
      fix(date,n);
      for(j=n-1;j>=0;j--)if(date[j]!=0||j!=0)printf("%d",date[j]);
      printf("\n");
      return(0);
}

int fix(int a[],int x)
{
    int m,i,tmp=0,tmp2=0;
    for(i=0;i<x;i++)
    {
                    tmp=(a[i]+tmp2)%10;
                    tmp2=(a[i]+tmp2-tmp)/10;
                    a[i]=tmp;
    }
    if(tmp2!=0)a[i+1]=tmp2;
}
