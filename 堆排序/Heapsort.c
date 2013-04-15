#include<stdio.h>
int n;
main()
{
      freopen("Heapsort.in","r",stdin);
      freopen("Heapsort.out","w",stdout);
      int Heapify(int date[],int x);
      int Heapsort(int date[],int x);
      int father(int x);
      int right(int x);
      int left(int x);
      int a[100000],i;
      scanf("%d",&n);
      for(i=1;i<=n;i++)scanf("%d",&a[i]);
      return 0;
}

int father(int x)
{
    if(x%2==0)return x/2;
    else return (x-1)/2;
}

int right(int x)
{
    return 2*x+1;
}

int left(int x)
{
    return 2*x;
}

int Heapify(int date[],int x)
{
    int l=left(x),r=right(x),largest;
    if(l<=n&&)
