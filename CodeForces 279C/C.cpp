#include<iostream>
#include<cstdio>
using namespace std;
int data[100005];
int treex[250000];
int treey[250000];
int treem[250000];
int treed[250000];
int main()
{
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  int n,m;
  void build(int a,int x,int y);
  int make(int a,int x,int y);
  cin>>m>>n;
  for(int i=1;i<=n;i++)cin>>data[i];
  build(1,1,n);
  for(int i=1;i<=30;i++)cout<<treex[i]<<" "<<treem[i]<<" "<<treey[i]<<" "<<treed[i]<<endl; 
  make(1);
  return 0;
}

void build(int a,int x,int y)
{
    int t=y-x;
    treex[a]=x;
    treey[a]=y;
    treed[a]=-1;
    if(t==0)
    {
      treed[a]=1;
      treem[a]=x;
      return;
    }
    if(t==1)
    {
      treem[a]=y;
      treex[2*a]=x;
      treey[2*a]=x;
      treem[2*a]=x;
      treed[2*a]=1;
      treex[2*a+1]=y;
      treey[2*a+1]=y;
      treem[2*a+1]=y;
      treed[2*a+1]=1;
      return;
    }
    if(t%2==0)
    {
      treem[a]=x+t/2;
      build(2*a,x,x+t/2-1);
      build(2*a+1,x+t/2,y);
    }
    else
    {
      treem[a]=x+(t+1)/2;
      build(2*a,x,x+(t+1)/2-1);
      build(2*a+1,x+(t+1)/2,y);
    }
}

int make(int a)
{
  int t=treey[a]-treex[a],tp1,tp2;
  if(t==0)
  {
  }
  tp1=make(a*2);
  tp2=make(a*2+1);
}
