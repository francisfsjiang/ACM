#include<iostream>
#include<cstdio>
#include<list>
#define MAX 5050
#include"timecounter.h"
using namespace std;
int movex[4]={1,-1,0,0};
int movey[4]={0,0,1,-1};
bool map[MAX][MAX];
int lsx[MAX*MAX];
int lsy[MAX*MAX];
int lsd[MAX*MAX];
int lsl[MAX*MAX];
int n,m;

bool check(int x,int y)
{
  if(x>=1&&x<=n&&y>=1&&y<=m&&!map[x][y])return true;
  else return false;
}

void outer(int x)
{
  if(lsl[x]==1)
  {
    cout<<lsx[x]<<" "<<lsy[x]<<endl;
    map[lsx[x]][lsy[x]]=2;
  }
  else
  {
    outer(lsl[x]);
    cout<<lsx[x]<<" "<<lsy[x]<<endl;
    map[lsx[x]][lsy[x]]=2;
  }
}

void out()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(map[i][j]!=2)printf(" ",map[i][j]);
      else printf("*");
    }
    printf("\n");
  }
}

int main()
{
  freopen("make.out","r",stdin);
  freopen("solve.out","w",stdout);
  int startx,starty,endx,endy,headx,heady,headd,len=0,lener,head,end,temp;
  bool sign;
  cin>>headx>>headx>>n>>m>>startx>>starty>>endx>>endy;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
  {
    cin>>temp;
    map[i][j]=temp;
  }
  head=0;
  end=0;
  lsx[head]=(startx);
  lsy[head]=(starty);
  lsd[head]=(0);
  lsl[head]=-1;
  end++;
  map[startx][starty]=1;
  sign=true;
  while(sign&&head<end)
  {
    headx=lsx[head];
    heady=lsy[head];
    headd=lsd[head];
    for(int i=0;i<4;i++)
    {
      if(check(headx+movex[i],heady+movey[i]))
      {
        //cout<<headx+movex[i]<<" "<<heady+movey[i]<<endl;
        lsx[end]=(headx+movex[i]);
        lsy[end]=(heady+movey[i]);
        lsd[end]=(headd+1);
        lsl[end]=head;
        end++;
        map[headx+movex[i]][heady+movey[i]]=1;
        if(headx+movex[i]==endx&&heady+movey[i]==endy)
        {
          len=headd+1;
          lener=end-1;
          sign=false;
          break;
        }
      }
    }
    head++;
  }
  if(len!=0)
  {
    //cout<<len<<endl;
    //outer(lener);
    out();
  }
  else cout<<"No Way Out"<<endl;
  return 0;
}
