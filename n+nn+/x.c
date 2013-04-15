#include<stdio.h>
main()
{
      freopen("x.in","rt+",stdin);    
      freopen("x.out","wt+",stdout);
      int i,j,n;
      int date1[200000],date2[200000];
      int fix(int a[],int x);
      scanf("%d",&n);
      printf("%d\n",n);
      memset(date2,0,sizeof(date2));
      for(i=0;i<n;i++)
      {
                      //printf("-------------------------------------------------\n");
                      date1[i]=1;
                      for(j=0;j<=i;j++)date2[j]=date2[j]+date1[j];
                      //for(j=i;j>=0;j--)printf("%d ",date2[j]);
                      //printf("\n");                      
                      fix(date2,i+2);
                      for(j=i;j>=0;j--)if(date2[j]!=0||j!=0)printf("%d",date2[j]);
                      printf("\n");
                      //printf("-------------------------------------------------\n");
      }
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
