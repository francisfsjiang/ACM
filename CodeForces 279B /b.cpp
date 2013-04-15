#include<iostream>
#include<cstdio>
using namespace std;
int data[100005];
int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int n,t,last,total,max=0,head,end;
  cin>>n>>t;
  for(int i=0;i<n;i++)cin>>data[i];
  head=0;
  end=0;
  max=0;
  last=t;
  total=0;
  while(1)
  {
    //cout<<head<<endl<<end<<endl<<last<<endl<<"---"<<endl;
    int i;
    for(i=end;i<n;i++)
    {
      if(last-data[i]>=0)
      {
	last-=data[i];
	total++;
      }
      else break;
    }
    //cout<<total<<endl;
    end=i;
    if(total>max)max=total;
    if(end==n-1||end==n)break;
    total--;
    last+=data[head];
    head++;
  }
  cout<<max;
  return 0;
}
