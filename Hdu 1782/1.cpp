#include<iostream>
#include<cstdio>
#include<queue>
#include<string.h>
#define MAX 30
using namespace std;
int movex[4]={-1,0,1,0};
int movey[4]={0,1,0,-1};
//int fact[11]={0,1,2,4,8,16,32,64,128,256,512};
struct point
{
  int x,y,step;
  //int key[11];
  int keyid;
};

int n,m,startx,starty,endx,endy,moststep;
bool map[MAX][MAX]={0};
bool used[MAX][MAX][1024]={0};
int keymap[MAX][MAX];

queue<point> lists;

void print1()
{
  for(int i=1;i<=m;i++)
    {
      for(int j=1;j<=n;j++)
      {
        printf("%d ",map[i][j]);
      }
      printf("\n");
    }
    printf("\n");
}

void print2()
{
  for(int i=1;i<=m;i++)
    {
      for(int j=1;j<=n;j++)
      {
        printf("%d ",keymap[i][j]);
      }
      printf("\n");
    }
    printf("\n");
}
void print(point a)
{
  cout<<"---"<<a.x<<" "<<a.y<<endl;
  for(int i=1;i<=10;i++)cout<<i<<" ";
  cout<<endl;
  int temp=1;
  for(int i=1;i<=10;i++)
  {
    cout<<(temp&a.keyid)<<" ";
    temp=temp<<1;
  }
  cout<<endl<<a.keyid<<endl<<"-------"<<endl;

}

bool check(point a)
{
  if(a.x>=1&&a.x<=m&&
  a.y>=1&&a.y<=n&&
  map[a.x][a.y]==0&&
  used[a.x][a.y][a.keyid]==0&&
  a.step<=moststep)
  {
    int nowkey=keymap[a.x][a.y];
    if(nowkey==0)return true;
    else if(nowkey>0)return true;
    else
    {
      if(a.keyid&(1<<(-nowkey)))return true;
      else return false;
    }
  }
  else return false;
}

int main()
{
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int nowkey;
  char str[MAX];
  while(scanf("%d%d%d",&m,&n,&moststep)!=EOF)
  {
    moststep--;
    endx=0;
    endy=0;
    memset(used,0,sizeof(used));
    while(!lists.empty())lists.pop();
    for(int i=1;i<=m;i++)
    {
      scanf("%s",str);

      for(int j=1;j<=n;j++)
      {
        if(str[j-1]=='@')
        {
          startx=i;
          starty=j;
          map[i][j]=0;
          keymap[i][j]=0;
        }
        else if(str[j-1]=='^')
        {
          endx=i;
          endy=j;
          map[i][j]=0;
          keymap[i][j]=0;
        }
        else if(str[j-1]=='*')
        {
          map[i][j]=1;
          keymap[i][j]=0;
        }
        else if(str[j-1]=='.')
        {
          map[i][j]=0;
          keymap[i][j]=0;
        }
        else
        {
          map[i][j]=0;
          if(str[j-1]<='z'&&str[j-1]>='a')keymap[i][j]=str[j-1]-'a'+1;
          else keymap[i][j]=-(str[j-1]-'A'+1);
        }
      }
    }
    //print1();
    //print2();
    point start;
    start.x=startx;
    start.y=starty;
    //for(int i=0;i<=10;i++)start.key[i]=0;
    start.keyid=0;
    start.step=0;
    used[start.x][start.y][start.keyid]=1;
    lists.push(start);
    point iter;
    point temp;
    int sign=1;
    while(!lists.empty()&&sign)
    {
      iter=lists.front();
      //cout<<"----"<<(*iter).x<<" "<<(*iter).y<<" "<<(*iter).step<<endl;
      //print(*iter);
      for(int i=0;i<4;i++)
      {
        temp.x=iter.x+movex[i];
        temp.y=iter.y+movey[i];
        temp.keyid=iter.keyid;
        temp.step=iter.step+1;
        if(check(temp))
        {
          //cout<<check(temp.x,temp.y,i)<<temp.x<<" "<<temp.y<<" "<<temp.step<<endl;
          if(temp.x==endx&&temp.y==endy)
          {
            sign=0;
            printf("%d\n",temp.step);
            break;
          }
          nowkey=keymap[temp.x][temp.y];
          if(nowkey>0)temp.keyid=temp.keyid|(1<<(nowkey));
          lists.push(temp);
          used[temp.x][temp.y][temp.keyid]=1;
        }
      }
      lists.pop();
    }
    if(sign)printf("-1\n");
  }
  return 0;
}
