#include<iostream>
#include<cstdio>
#define MAX 500000
using namespace std;
int data[MAX],temp[MAX];
//int time[MAX];

long long mergearr(int s,int t)
{
  int i=s;
  long long sum=0;
  int j=(s+t)/2+1;
  int mid=(s+t)/2,len=s;
  while(i<=mid&&j<=t)
  {
    if(data[i]<data[j])
    {
      temp[len]=data[i];
      i++;
      len++;
    }
    else
    {
      temp[len]=data[j];
      j++;
      len++;
      sum+=j-len;
    }
  }
  while(i<=mid)
  {
    temp[len]=data[i];
    i++;
    len++;
  }
  while(j<=t)
  {
    temp[len]=data[j];
    j++;
    len++;
  }
  for(int i=s;i<=t;i++)
  {
    data[i]=temp[i];
  }
  return sum;
}

long long mergesort(int s,int t)
{
  int mid=(s+t)/2;
  long long sum=0;
  //cout<<s<<" "<<mid<<" "<<t<<endl;
  if(s<t)
  {
    sum+=mergesort(s,mid);
    sum+=mergesort(mid+1,t);
    sum+=mergearr(s,t);
  }
  return sum;
}

int main()
{
  freopen("merge.in","r",stdin);
  freopen("merge.out","w",stdout);
  int n;
  long long sum;
  while(1)
  {
    scanf("%d",&n);
    if(n==0)break;
    for(int i=0;i<n;i++)scanf("%d",&data[i]);
    sum=mergesort(0,n-1);
    //for(int i=0;i<n;i++)printf("%d ",data[i]);
    printf("%I64d\n",sum);
    //for(int i=0;i<n;i++)printf("%d ",time[i]);
  }
  return 0;
}
