#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int m,n,i,j,max,sum;
    int data[105][105];
    int sign[105]={0};
    char s[1000];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
        for(j=0;j<m;j++)data[i][j+1]=s[j]-48;
    }
    for(i=1;i<=m;i++)
    {
        max=0;
        for(j=1;j<=n;j++)if(data[j][i]>max)max=data[j][i];
        for(j=1;j<=n;j++)if(data[j][i]==max)sign[j]++;
    }
    sum=0;
    for(i=1;i<=n;i++)if(sign[i]>0)sum++;
    printf("%d",sum);
    return 0;
}
