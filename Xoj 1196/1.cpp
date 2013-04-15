#include<iostream>
#include<cstdio>
#include<list>
#include<string.h>
#define MAX 50
using namespace std;

int movex[4]={-1,0,1,0};
int movey[4]={0,1,0,-1};
struct point
{
  int x,y,step;
};

int n,m;
bool map[MAX][MAX][4]={0};
bool used[MAX][MAX]={0};

list<point> lists;

void print()
{
  for(int i=1;i<=m;i++)
    {
      for(int j=1;j<=n;j++)
      {
        for(int k=0;k<4;k++)printf("%d",map[i][j][k]);
        printf(" ");
      }
      printf("\n");
    }
    printf("\n");
}

bool check(int ox,int oy,int x,int y,int i)
{
  //cout<<"**"<<x<<y<<i<<endl;
  if(x>=1&&x<=m&&y>=1&&y<=n&&
  ox>=1&&ox<=m&&oy>=1&&oy<=n&&
  map[ox][oy][i]==0&&
  used[x][y]==0)return true;
  else return false;
}

int main()
{
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int x;
  while(1)
  {
    scanf("%d%d",&n,&m);
    if(m==0&&n==0)break;
    memset(used,0,sizeof(used));
    lists.clear();
    //print();
    for(int j=1;j<=n;j++)
    {
      map[1][j][0]=1;
      map[m][j][2]=1;
    }
    for(int i=1;i<=m;i++)
    {
      map[i][1][3]=1;
      map[i][n][1]=1;
    }
    //print();
    for(int j=1;j<n;j++)
    {
      scanf("%d",&x);
      map[1][j+1][3]=map[1][j][1]=x;
    }
    //print();
    for(int i=1;i<m;i++)
    {
      for(int j=1;j<=n;j++)
      {
        scanf("%d",&x);
        map[i+1][j][0]=map[i][j][2]=x;
      }
      for(int j=1;j<n;j++)
      {
        scanf("%d",&x);
        map[i+1][j+1][3]=map[i+1][j][1]=x;
      }
    }
    //print();
    point start;
    start.x=m;
    start.y=n;
    start.step=1;
    used[start.x][start.y]=1;
    lists.push_back(start);
    list<point>::iterator iter;
    point temp;
    int sign=1;
    while(lists.size()>0&&sign)
    {
      iter=lists.begin();
      //cout<<"----"<<(*iter).x<<" "<<(*iter).y<<" "<<(*iter).step<<endl;
      for(int i=0;i<4;i++)
      {
        temp.x=(*iter).x+movex[i];
        temp.y=(*iter).y+movey[i];
        temp.step=(*iter).step+1;

        if(check((*iter).x,(*iter).y,temp.x,temp.y,i))
        {
          //cout<<check(temp.x,temp.y,i)<<temp.x<<" "<<temp.y<<" "<<temp.step<<endl;
          if(temp.x==1&&temp.y==1)
          {
            sign=0;
            cout<<temp.step<<endl;
            break;
          }
          lists.push_back(temp);
          used[temp.x][temp.y]=1;
        }
      }
      lists.pop_front();
    }
    if(sign)printf("0\n");
  }
  return 0;
}
