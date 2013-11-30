#include<iostream>
#include<cstdio>
#define bugs(a,b) cout<<#a<<" ";for(int zz=0;zz<=b;zz++)cout<<a[zz]<<" ";cout<<endl;
#define bug(a) cout<<#a<<"="<<a<<endl;
using namespace std;

const int mod=100000000;
int m,n,index;
int state[2000];
int map[20];
int dp[20][2000];

void init()
{
	int max=1<<n;
	index=0;
	for(int i=0;i<max;i++)
	{
		if(!(i&(i<<1)))
		{
			state[index++]=i;
		}
	}
}

bool fix(int x,int y)
{
	if(x&y)return 0;
	else return 1;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&m,&n);
	int temp;
	bool sign;
	for(int i=0;i<m;i++)
	{
		temp=1;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&sign);
			if(!sign)map[i]+=temp;
			temp=temp<<1;
		}
	}
	init();
	//bugs(map,m)
	//bugs(state,index-1);
	for(int j=0;j<index;j++)
	{
		if(fix(state[j],map[0]))dp[0][j]=1;
	}
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<index;j++)
		{
			if(!fix(state[j],map[i]))continue;
			for(int k=0;k<index;k++)
			{
				if(!fix(state[k],map[i-1]))continue;
				if(!(state[k]&state[j]))dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
			}
		}
	}
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<index;j++) cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	int sum=0;
	for(int i=0;i<index;i++)
	{
		sum=(sum+dp[m-1][i])%mod;
	}
	printf("%d",sum);
	return 0;
}
