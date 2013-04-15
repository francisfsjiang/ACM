#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  freopen("test.in","r",stdin);
  freopen("test.out","w",stdout);
  string s1,s2;
  int n,sum,temp,pos,len;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    sum=0;
    cin>>s1>>s2;
    len=s1.size();
    pos=0;
    //cout<<s2<<endl<<s2<<endl;
    while(1)
    {
      temp=s2.find(s1,pos);
      //cout<<temp<<endl;
      if(temp==-1)break;
      else
      {
	sum++;
	pos=temp+1;
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}

