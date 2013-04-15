#include<iostream>
#include<cstdio>
using namespace std;
int movex[4]={1,0,-1,0};
int movey[4]={0,1,0,-1};
int main()
{
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int endx,endy;
  int nowx=0,nowy=0,sum=0,dir=0;
  double step=1;
  cin>>endx>>endy;
  if(endx==0&&endy==0)
  {
    cout<<"0"<<endl;
    return 0;
  }
  while(1)
  {
    for(int i=1;i<=step;i++)
    {
      nowx+=movex[dir];
      nowy+=movey[dir];
      //cout<<nowx<<" "<<nowy<<endl;
      if(nowx==endx&&nowy==endy)
      {
	cout<<sum<<endl;
	return 0;
      }
    }
    step+=0.5;
    dir++;
    if(dir==4)dir=0;
    sum++;
  }
  return 0;
}
