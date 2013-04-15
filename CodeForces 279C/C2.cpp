#include<iostream>
#include<cstdio>
using namespace std;
int data[100005];
int lefts[100005]={0};
int rights[100005]={0};
int main()
{
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  int m,n;
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>data[i];
  
  //for(int i=1;i<=n;i++)cout<<data[i]<<endl;
  data[0]=-1;
  data[n+1]=-1;
  for(int i=1;i<=n;i++)
  {
  //cout<<data[i-1]<<" "<<data[i]<<endl;
    if(data[i-1]>=data[i])
    {
      lefts[i]=lefts[i-1]+1;
    }
    else lefts[i]=0;
  }
  for(int i=n;i>=1;i--)
  {
    if(data[i+1]>=data[i])
    {
      rights[i]=rights[i+1]+1;
    }
    else rights[i]=0;
  }
  //for(int i=1;i<=n;i++)cout<<lefts[i]<<" "<<rights[i]<<endl;
  int x,y,temp;
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    temp=lefts[y]+rights[x];
    if(temp>=y-x)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    //cout<<temp<<endl;
  }
  return 0;
}
