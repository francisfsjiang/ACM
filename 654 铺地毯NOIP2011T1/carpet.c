#include<stdio.h>
main()
{
      freopen("carpet.in","r",stdin);
      freopen("carpet.out","w",stdout);
      int i,n,x,y,sum=-1,data[10002][4];
      scanf("%d",&n);
      for(i=0;i<n;i++)scanf("%d%d%d%d",&data[i][0],&data[i][1],&data[i][2],&data[i][3]);
      scanf("%d%d",&x,&y);
      for(i=0;i<n;i++)
      {
                        if(data[i][0]<=x&&data[i][1]<=y&&data[i][0]+data[i][2]>=x&&data[i][1]+data[i][3]>=y)sum=i+1;
      }
      printf("%d",sum);
      return(0);
}
