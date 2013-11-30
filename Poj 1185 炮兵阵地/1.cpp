#include<iostream>
#include<cstdio>
#include<string>
#define bug(s) cout<<#s<<"="<<s<<endl;
#define bugs(a,b) cout<<#a<<" ";for(int zz=0;zz<=b;zz++)cout<<a[zz]<<" ";cout<<endl;
using namespace std;

int state[100];
int num[100];
int index;
int dp[105][100][100];
int map[105];
int m,n;
int count(int x)
{
    int c=0;
    while(x>0)
    {
	if(x&1)c++;
	x>>=1;
    }
    return c;
}
void init()
{
    index=0;
    int max=1<<m;
    for(int sta=0;sta<max;sta++)
    {
	if(sta&sta<<1||sta&sta<<2)continue;
	state[index]=sta;
	num[index++]=count(sta);
    }
}

int fit(int x,int y)
{
    if(state[x]&map[y])return 0;
    else return 1;
}


int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    char ch;
    scanf("%d%d",&n,&m);
    init();
    int temp;
    for(int i=0;i<n;i++)
    {
	temp=1;
	scanf("%c",&ch);
	for(int j=0;j<m;j++)
	{
	    scanf("%c",&ch);
	    if(ch=='H') map[i]+=temp;
	    temp<<=1;
	}
    }
    /*bugs(map,n)
    bug(index);
    bugs(num,index)
    bugs(state,index);*/
    if(n>0)for(int i=0;i<index;i++)if(fit(i,0))dp[0][i][0]=num[i];
    if(n>1)for(int i=0;i<index;i++)
    {
	if(!fit(i,0))continue;
	for(int j=0;j<index;j++)
	{
	    if(!fit(j,1))continue;
	    if(!(state[i]&state[j]))dp[1][j][i]=dp[0][i][0]+num[j];
	}
    }
    for(int row=2;row<n;row++)
    {
	for(int i=0;i<index;i++)
	{
	    if(!fit(i,row-2))continue;
	    for(int j=0;j<index;j++)
	    {
		if(!fit(j,row-1))continue;
		for(int k=0;k<index;k++)
		{
		    if(!fit(k,row))continue;
		    if((!(state[k]&state[j]))&&(!(state[k]&state[i])))
		    {
			dp[row][k][j]=max(dp[row][k][j],dp[row-1][j][i]+num[k]);
			//bug(row)
			//cout<<i<<" "<<j<<" "<<k<<" "<<dp[row][k][j]<<endl;
		    }
		}
	    }
	}
    }
    /*for(int row=0;row<n;row++)
    {
	bug(row);
	for(int i=0;i<index;i++)
	{
	    for(int j=0;j<index;j++)cout<<dp[row][i][j];
	    cout<<endl;
	}
    }*/
    int sum=0;
    for(int i=0;i<n;i++)for(int j=0;j<index;j++)for(int k=0;k<index;k++)if(dp[i][j][k]>sum)sum=dp[i][j][k];
    printf("%d",sum);
    return 0;
}

