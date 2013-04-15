#include<stdio.h>
int  a[5005];
int  f[5005];
int  b[5005];
int c[5005][501];
int main()
{
	int i,j,k=0,n;
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	n++;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)if(a[j]>a[i]&&f[j]>f[i])f[i]=f[j];
		f[i]++;
	}
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)if(a[i]==a[j])
	{
        b[i]=j;
        break;
    }
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)if((b[j]==0||b[j]>i)&&f[j]==f[i]-1&&a[j]>a[i])
			{
				for(k=1;k<=c[j][0];k++)
				{
					c[i][k]+=c[j][k];
					c[i][k+1]+=c[i][k]/10;
					c[i][k]%=10;
				}
				while(c[i][k]>=10){c[i][k+1]+=c[i][k]/10;c[i][k]%=10;k++;}
				while(c[i][k]==0)k--;
				if(k>=c[i][0])c[i][0]=k;
			}
		if(c[i][0]==0)
		{
            c[i][0]=1;
            c[i][1]=1;
        }
	}
	printf("%d ",f[n]-1);
	for(i=c[n][0];i>=1;i--)printf("%d",c[n][i]);
	printf("\n");
	return 0;
}
