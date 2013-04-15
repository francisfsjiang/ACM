#include<iostream>
#include<cstdio>
#include<list>
#include"timecounter.h"
using namespace std;
int movex[4]={1,-1,0,0};
int movey[4]={0,0,1,-1};
bool map[5000][5000];
int n,m;

bool check(int x,int y)
{
  if(x>=1&&x<=n&&y>=1&&y<=m&&!map[x][y])return true;
  else return false;
}

int main()
{
  freopen("make.out","r",stdin);
  freopen("solve.out","w",stdout);
  list<short> lsx,lsy,lsd;
  int startx,starty,endx,endy,headx,heady,headd,len=0;
  bool sign;
  cin>>n>>m>>startx>>starty>>endx>>endy;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>map[i][j];
  lsx.push_back(startx);
  lsy.push_back(starty);
  lsd.push_back(0);
  map[startx][starty]=1;
  sign=true;
  while(sign&&!lsx.empty())
  {
    headx=lsx.front();
    heady=lsy.front();
    headd=lsd.front();
    for(int i=0;i<4;i++)
    {
      if(check(headx+movex[i],heady+movey[i]))
      {
	if(headx+movex[i]==endx&&heady+movey[i]==endy)
	{
	  len=headd+1;
	  sign=false;
	  break;
	}
	lsx.push_back(headx+movex[i]);
	lsy.push_back(heady+movey[i]);
	lsd.push_back(headd+1);
	map[headx+movex[i]][heady+movey[i]]=1;
      }
    }
    lsx.erase(lsx.begin());
    lsy.erase(lsy.begin());
    lsd.erase(lsd.begin());
  }
  if(len!=0)cout<<len;
  else cout<<"No Way Out"<<endl;
  return 0;
}
