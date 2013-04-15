#include<iostream>
#include<cstdio>
#define MAX 50050
using namespace std;
//int tree[MAX];
struct
{
  int left,right,mid;
  int lval,rval,mval;
  int state;
  int len()
  {
    return right-left+1;
  }
}tree[100050];

int max(int x,int y)
{
  if(x>y)return x;
  else return y;
}

void update(int i)
{
  int lson=i<<1,rson=(i<<1)+1;
  if(tree[lson].state==0&&tree[rson].state==0)
  {
    tree[i].state=0;
    return;
  }
  if(tree[lson].state==1)tree[i].lval=tree[lson].len()+tree[rson].lval;
  else if(tree[lson].state==0)tree[i].lval=tree[rson].lval;
  else tree[i].lval=tree[lson].lval;
  if(tree[rson].state==1)tree[i].rval=tree[rson].len()+tree[lson].rval;
  else if(tree[rson].state==0) tree[i].rval=tree[lson].rval;
  else tree[i].rval=tree[rson].rval;
  if(tree[i].lval+tree[i].rval>=tree[i].left-tree[i].right+1)
  {
    tree[i].lval=tree[i].lval;
    tree[i].rval=tree[i].lval;
    tree[i].mval=tree[i].lval;
    tree[i].state=1;
  }
  else
  {
    tree[i].mval;
    tree[i].mval=max(tree[i].lval,tree[i].mval);
    tree[i].mval=max(tree[i].rval,tree[i].mval);
    tree[i].mval=max(tree[lson].mval,tree[i].mval);
    tree[i].mval=max(tree[rson].mval,tree[i].mval);
    tree[i].state=2;
  }
}

int in(int i,int sum)
{
  int lson=i<<1,rson=(i<<1)+1;
  if(tree[lson].mval>=sum)in(lson,sum);
  else if(tree[rson].mval>=sum)in(rson,sum);
  else return 0;
}

void out(int s,int t,int d)
{
  if(s==tree[d].left&&t==tree[d].right)
  {
    tree[d].lval=tree[d].right-tree[d].left+1;
    tree[d].rval=tree[d].lval;
    tree[d].mval=tree[d].lval;
    while(d!=1)
    {
      update(d);
      d=d/2;
    }
    update(1);
  }
  if(s<=tree[d].left)
  {
    if(t<=tree[d].left)out(s,t,d<<1);
    else
    {
      out(s,tree[d].left,d<<1);
      out(tree[d].left+1,t,(d<<1)+1);
    }
  }
  else
  {
    out(s,t,(d<<1)+1);
  }
}
void build(int s,int t,int d)
{
  if(s==t)
  {
    tree[d].left=s;
    tree[d].right=s;
    tree[d].mid=s;
    tree[d].lval=1;
    tree[d].rval=1;
    tree[d].mval=1;
    tree[d].state=1;
    return;
  }
  tree[d].left=s;
  tree[d].right=t;
  tree[d].mid=(s+t)>>1;
  build(s,tree[d].mid,d<<1);
  build(tree[d].mid+1,t,(d<<1)+1);
  update(d);
}

int main()
{
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int n,m,d;
  scanf("%d%d",&n,&m);
  build(1,n,1);
  for(int i=1;i<=n<<1;i++)printf("%2d ",tree[i].left);
  cout<<endl;
  for(int i=1;i<=n<<1;i++)printf("%2d ",tree[i].right);
  cout<<endl;
  for(int i=1;i<=n<<1;i++)printf("%2d ",tree[i].mid);
  cout<<endl;
  for(int i=1;i<=n<<1;i++)printf("%2d ",tree[i].lval);
  cout<<endl;
  for(int i=1;i<=n<<1;i++)printf("%2d ",tree[i].rval);
  cout<<endl;
  for(int i=1;i<=n<<1;i++)printf("%2d ",tree[i].mval);
  cout<<endl;
  for(int i=1;i<=n<<1;i++)printf("%2d ",tree[i].state);
  cout<<endl;
  /*while(1)
  {
    scanf("%d",&d);
    if(d==1)
    {
      scanf("%d",&x);
    }
    else
    {
      scanf("%d%d",&x,&y);
    }
  }*/
  return 0;
}
