#include<stdio.h>
int s[10000000],n;
main()
{
      int i;
      //int quicksort(int date[],int s,int t);
      freopen("Quicksort.in","rt+",stdin);    
      freopen("Quicksort.out","wt+",stdout);
      scanf("%d",&n);
      for(i=0;i<n;i++)scanf("%d",&s[i]);
      qsort(s,0,n-1);
      for(i=0;i<n;i++)printf("%d ",s[i]);
}
