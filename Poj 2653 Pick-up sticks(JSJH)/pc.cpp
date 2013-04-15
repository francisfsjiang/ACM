#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}
int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}
struct edge
{
    int x[2],y[2];
};
vector<edge> map(1500);

int direction(struct edge a,struct edge b,int d)
{
    return (b.x[d]-a.x[0])*(a.y[1]-a.y[0])-(b.y[d]-a.y[0])*(a.x[1]-a.x[0]);
}

int quickexclude(struct edge a,struct edge b)
{
    if(max(min(a.x[0],a.x[1]),min(b.x[0],b.x[1]))>
            min(max(a.x[0],a.x[1]),max(b.x[0],b.x[1]))||
            max(min(a.y[0],a.y[1]),min(b.y[0],b.y[1]))>
            min(max(a.y[0],a.y[1]),max(b.y[0],b.y[1])))return false;
    else return true;
}

int meet(struct edge a,struct edge b)
{
    if(!quickexclude(a,b))return false;
    else
    {
        int d1=direction(b,a,0),d2=direction(b,a,1),d3=direction(a,b,0),d4=direction(a,b,1);
        //cout<<endl<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
        if(d1*d2<0&&d3*d4<0)
        {
            return true;
        }
        else return false;
   }
}

int main()
{
    freopen("pc.in","r",stdin);
    freopen("pc.out","w",stdout);
    int n,x,y;
    struct edge temp;
    cin>>n;
    cin>>lookx>>looky;
    cin>>x>>y;
    map[0].x[0]=x;
    map[0].y[0]=y;
    map[n-1].x[1]=x;
    map[n-1].y[1]=x;
    for(int i=1; i<n; i++)
    {
      cin>>x>>y;
      map[i-1].x[1]=x;
      map[i-i].y[1]=y;
      map[i].x[0]=x;
      map[i].y[0]=y;
    }
    for(int i=0;i<n-1;i++)
    {
      for(int j=i+1;j<n;j++)
      {
	  if(meet(map[j],map[i]))
	  {
	    cout<<"NOFENCE"<<endl;
	    return 0;
	  }
      }
    }
	    
    }
    return 0;
}

