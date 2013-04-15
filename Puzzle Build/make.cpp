#include<iostream>
#include<cstdio>
#include<list>
#include<time.h>
#include<stdlib.h>
#include"timecounter.h"
using namespace std;
bool map[5000][5000]={true};
list<short> lsx,lsy,lsd;
int movex[4]={1,-1,0,0};
int movey[4]={0,0,1,-1};
int m,n;
bool check(int x,int y)
{
  if(x>=1&&x<=n&&y>=1&&y<=m&&map[x][y])return true;
  else return false;
}

void insert(int x,int y)
{
  bool rd;
  map[x][y]=0;
  rd=rand()%2;
  if(rd)
  {
    for(int i=0;i<4;i++)if(check(x+movex[i],y+movey[i]))
    {
      lsx.push_back(x+movex[i]);
      lsy.push_back(y+movey[i]);
      lsd.push_back(i);
    }
  }
  else
  {
    for(int i=3;i>=0;i--)if(check(x+movex[i],y+movey[i]))
    {
      lsx.push_back(x+movex[i]);
      lsy.push_back(y+movey[i]);
      lsd.push_back(i);
    }
  }
}

void makedoor(int x,int y)
{
  while(map[x][y])
  {
    map[x][y]=0;
    map[x][y-1]=0;
    map[x-1][y]=0;
    x--;
    y--;
  }
}

int main()
{
  Time_start();
  freopen("make.in","r",stdin);
  freopen("make.out","w",stdout);
  int startx,starty,endx,endy,len;
  int rd;
  list<short>::iterator headx,heady,headd;
  //srand(time(NULL));
  scanf("%d%d%d%d%d%d",&n,&m,&startx,&starty,&endx,&endy);
  if((n<=1&&m<=1)||(startx==endx&&starty==endy)||startx>n||startx<1||starty>m||starty<1||endx>n||endx<1||endy>m||endy<1)
  {
    cout<<"Fuck You"<<endl;
    return 0;
  }
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)map[i][j]=1;
  insert(startx,starty);
  //insert(endx,endy);
  while(!lsx.empty())
  {
    headx=lsx.begin();
    heady=lsy.begin();
    headd=lsd.begin();
    len=lsx.size();
    rd=rand()%len;
    for(int i=0;i<rd;i++)
    {
      headx++;
      heady++;
      headd++;
    }
    if(check(*headx+movex[*headd],*heady+movey[*headd]))
    {
	insert(*headx+movex[*headd],*heady+movey[*headd]);
	map[*headx][*heady]=0;
    }
    lsx.erase(headx);
    lsy.erase(heady);
    lsd.erase(headd);
  }
  if(map[endx][endy])makedoor(endx,endy);
  printf("%d %d\n%d %d\n%d %d\n",n,m,startx,starty,endx,endy);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)printf("%d ",map[i][j]);
    printf("\n");
  }
  Time_end();
  return 0;
}

