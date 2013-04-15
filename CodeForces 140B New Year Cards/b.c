#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,i,j,k;
    int data[305][305];
    int re[305]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&data[i][j]);
    for(i=1;i<=n;i++)scanf("%d",&re[i]);
    //for(i=1;i<=n;i++){for(j=1;j<=n;j++)printf("%d",data[i][j]);printf("\n");}
    for (i=1;i<=n;i++)
    {
		for (j=1;;j++) if (data[i][j]!=i)
		{
			for (k=1;re[k]>data[i][j]||re[k]==i;k++);
			printf("%d\n",k);
			if (re[k]==data[i][j])break;
		}
		printf("\n--%d \n",data[i][j]);
	}
	return 0;
}
