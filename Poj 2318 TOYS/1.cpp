#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int uplimit,downlimit,start,end;
struct line
{
  int up;
  int down;
};
vector<line> list;
bool cmp(const line& a,const line& b)
{
  if(a.up<b.up||a.down<b.down)return true;
  else return false;
}
bool xx(const line& p0,int x,int y)
{
  if()
int search(int x,int y,int s,int t)
{
  int mid=(t+s)/2;

int main()
{
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int m,n;
  line temp;
  while(1)
  {
    scanf("%d",&n);
    if(n==0)break;
    scanf("%d%d%d%d%d",&m,&start,&uplimit,&end,&downlimit);
    list.clear();
    for(int i=0;i<n;i++)
    {
      scanf("%d%d",&temp.up,&temp.down);
      list.push_back(temp);
    }
    //sort(list.begin(),list.end(),cmp);
    for(int i=0;i<n;i++)
    {
      printf("%d %d\n",list[i].up,list[i].down);
    }
    for(int i=0;i<m;i++)scanf("%d%d",&n,&n);
  }
  return 0;
}
