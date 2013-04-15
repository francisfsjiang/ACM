#include<stdio.h>
main()
{
      int s[101],re[1005]={0},i,j,sum,n;
      int quicksort(int date[],int s,int t);
      freopen("ming.in","rt+",stdin);
      freopen("ming.out","wt+",stdout);
      scanf("%d",&n);
      for(i=0;i<n;i++)scanf("%d",&s[i]);
      for(i=0;i<n;i++)re[s[i]]++;
      for(i=1;i<=1000;i++)if(re[i]>0)sum++;
      printf("%d\n",sum);
      for(i=1;i<=1000;i++)if(re[i]>0)printf("%d ",i);
      return(0);
}
