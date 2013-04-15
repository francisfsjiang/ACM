#include <stdio.h>
int main()
{
freopen("tree.in","rt+",stdin);
freopen("tree.out","wt+",stdout);
int L,M,i,j;
int a[10001];
for(i=0;i<10001;i++) a[i]=1;
scanf("%d %d",&L,&M);
for(i=0;i<M;i++)
{
int begin,end;
scanf("%d %d",&begin,&end);
for(j=begin;j<=end;j++)
{
a[j]=0;
}
}
int count=0;
for(i=0;i<=L;i++)
{
if(a[i]==1) count++; 
}
printf("%d",count);
return 0;
}
