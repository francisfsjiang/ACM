#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define N 10
char a[N][N];
int n,m,t;	//存储矩阵维数和规定的时间
bool result;
int doorx,doory;	//存储出口的坐标
void SearchWay(int x,int y,int cnt)
{
	if(result) return;
	if(a[x][y]=='D'&&cnt==t)
	{
		result=true;
		return;
	}
	if(cnt>t||((t-cnt)-abs(x-doorx)-abs(y-doory))%2!=0)
		return;	//每次都要判断是否存在到达终点为奇数步的情况，出现则马上退出，说明不能出去
	char temp=a[x][y];
	a[x][y]='X';
	if(!result&&x>1&&(a[x-1][y]=='.'||a[x-1][y]=='D')) SearchWay(x-1,y,cnt+1);
	if(!result&&x<n&&(a[x+1][y]=='.'||a[x+1][y]=='D')) SearchWay(x+1,y,cnt+1);
	if(!result&&y>1&&(a[x][y-1]=='.'||a[x][y-1]=='D')) SearchWay(x,y-1,cnt+1);
	if(!result&&y<m&&(a[x][y+1]=='.'||a[x][y+1]=='D')) SearchWay(x,y+1,cnt+1);
	a[x][y]=temp;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
	while(1)
	{
		scanf("%d%d%d",&n,&m,&t);
		int sx,sy;	//存储起点的坐标
		if(!n&&!m&&!t) break;
		int i,j;
		result=false;
		for(i=1;i<n+1;i++)
		{
			//getchar();
			for(j=1;j<m+1;j++)
			{
				//scanf("%c",&a[i][j]);
				cin>>a[i][j];
				if(a[i][j]=='S')
				{
					sx=i;sy=j;
				}
				if(a[i][j]=='D')
				{
					doorx=i;doory=j;
				}
			}
		}
		if((abs(sx-doorx)+abs(sy-doory)-t)%2==0)
			SearchWay(sx,sy,0);	//只有这个通过了才能进行下一步的动作
		if(result) printf("YES\n");
		else       printf("NO\n");
	}
	return 0;
}
