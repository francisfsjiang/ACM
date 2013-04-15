#include<stdio.h>
#include<string.h>
int data[1005][1005];
int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}
int up(int x,int y)
{
    x=x-2;
    y=y-1;
    if(x>=1&&y>=1&&y<=x)return data[x][y];
    else return max(data[x-1][y-1],data[x-1][y]);
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,i,j,max;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        memset(data,0,sizeof(data));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)scanf("%d",&data[i][j]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                data[i][j]+=up(i,j);
            }
        }
        max=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)if(data[i][j]>max)max=data[i][j];
        }
        printf("%d\n",max);
    }
    return 0;
}
