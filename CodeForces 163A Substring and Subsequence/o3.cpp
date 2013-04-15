#include<cstdio>
#include<cstring>
char x[5120],y[5120];
int n,m,a,f[5120][5120],i,j;
int main(){
freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
	n=strlen(gets(x+1));
	m=strlen(gets(y+1));
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(x[i]==y[j])(f[i][j]+=f[i-1][j-1]+1)%=1000000007;
			f[i][j+1]=f[i][j];
		}
		(a+=f[i][m])%=1000000007;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)printf("%2d ",f[i][j]);
		printf("\n");
    }
	return printf("%d\n",a),0;
}
