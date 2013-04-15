#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
const int MAX_SIZE=200+1;
const int direction[][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct point
{
 int x,y;
 point(int i,int j)
 {
  x=i;
  y=j;
 }
};
int flag;
queue<point>q;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int n,m;
int temp_steps;
int min_steps;
void clear()
{
 while (!q.empty())
 {
  q.pop();
 }
}
void BFS()
{
   point temp(0,0);
   int x,y;
   while (!q.empty())
   {
    temp=q.front();
    q.pop();
    if (temp.x==0&&temp.y==0)
    {
     temp_steps++;
     if (q.size()==0)
     {
      return ;
     }
     else
      q.push(point(0,0));
    }

    else
    {
     if (map[temp.x][temp.y]=='@')
     {
      dist[temp.x][temp.y]+=temp_steps;
     }
     for (int i=0;i<4;i++)
     {
      x=temp.x+direction[i][0];
      y=temp.y+direction[i][1];
      if (x>=1&&x<=n&&y>=1&&y<=m&&visited[x][y]==0)
      {
       if (map[x][y]!='#')
       {
        visited[x][y]=1;
        q.push(point(x,y));
       }
      }
     }
    }
   }
}
int main(int argc,char **argv)
{
    int i,j,k;
 point begin_y(0,0),begin_m(0,0);
freopen("in.in","r",stdin);
freopen("out.out","w",stdout);

 while (scanf("%d%d",&n,&m)!=EOF)
 {
  for (i=1;i<=n;i++)
  {
   for (j=1;j<=m;j++)
   {
    scanf(" %c",&map[i][j]);
    if (map[i][j]=='Y')
    {
     begin_y=point(i,j);
    }
    else if (map[i][j]=='M')
    {
     begin_m=point(i,j);
    }
   }
  }
  for (i=1;i<=n;i++)for (j=1;j<=m;j++)dist[i][j]=0;
  for (i=0;i<2;i++)
  {
            for (k=1;k<=n;k++)for (j=1;j<=m;j++)visited[k][j]=0;
   temp_steps=0;
   clear();
   if (i==0)
   {
    q.push(begin_y);
    visited[begin_y.x][begin_y.y]=1;

   }
   else
   {
      q.push(begin_m);
      visited[begin_m.x][begin_m.y]=1;
   }
   q.push(point(0,0));
   BFS();

  }
  min_steps=2147483640;
  for (i=1;i<=n;i++)
  {
   for (j=1;j<=m;j++)
   {
    if (dist[i][j]!=0&&min_steps>dist[i][j])
    {
     min_steps=dist[i][j];
    }
   }
  }
 printf("%d\n",min_steps*11);
 }
 return 0;
}
