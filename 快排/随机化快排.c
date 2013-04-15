#include<stdio.h>
int s[10000000],n;
main()
{
      int i;
      int quicksort(int s,int t);
      freopen("Quicksort.in","rt+",stdin);    
      freopen("Quicksort.out","wt+",stdout);
      scanf("%d",&n);
      for(i=0;i<n;i++)scanf("%d",&s[i]);
      quicksort(0,n-1);
      for(i=0;i<n;i++)printf("%d ",s[i]);
}

int quicksort(int x,int y)
{
int i,j,m,temp;
m=rand()%(y-x+1)+x;
i=x;
j=y;
while(i<=j)
{
          for(;s[i]<s[m];i++);
          for(;s[j]>s[m];j--);
          if(s[i]==s[m])i++;
          if(s[j]==s[m])j--;
          if(i<j)
          {
                 temp=s[i];
                 s[i]=s[j];
                 s[j]=temp;
          }
}
if(m<=j)
{
                 temp=s[m];
                 s[m]=s[j];
                 s[j]=temp;
}
else
{
                 temp=s[j+1];
                 s[j+1]=s[m];
                 s[m]=temp;
                 j++;
}
if(j-1>x)quicksort(x,j-1);
if(j+1<y)quicksort(j+1,y);
}
