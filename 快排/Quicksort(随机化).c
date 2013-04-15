#include<stdio.h>
int s[10000000],n;
main()
{
      int i;
      int quicksort(int date[],int s,int t);
      freopen("Quicksort.in","rt+",stdin);
      freopen("Quicksort.out","wt+",stdout);
      scanf("%d",&n);
      for(i=0;i<n;i++)scanf("%d",&s[i]);
      quicksort(s,0,n-1);
      for(i=0;i<n;i++)printf("%d ",s[i]);
}

int quicksort(int date[],int s,int t)
{
     int i,j,y,temp,m;
     m=rand()%(t-s+1)+s;
     temp=date[m];
     date[m]=date[s];
     date[s]=temp;
     i=s;
     j=t+1;
     y=date[s];
     for(;i<j;)
     {
                 for(i++;date[i]<y;i++);
                 for(j--;date[j]>y;j--);
                 if(i<j)
                 {
                        temp=date[i];
                        date[i]=date[j];
                        date[j]=temp;
                 }
     }
     date[s]=date[j];
     date[j]=y;
     if(s<j-1)quicksort(date,s,j-1);
     if(j+1<t)quicksort(date,j+1,t);
}
