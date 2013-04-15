#include<stdio.h>
#include<string.h>
#define min(a,b) a>b?b:a
int data[1005][1005];
int re[1005][1005];
int search(int x,int y)
{
    int i,j,sum=0,end=y-1;
    for(i=x-1;i>=1;i--)
    {
        for(j=min(i,y);j>=end;j--)
        {
            sum+=data[i][j];
        }
        if(end>1)end--;
    }
    printf("%d \n",sum);
    return sum;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,i,j,maxx;
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
                re[i][j]=data[i][j]+search(i,j);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)printf("%d ",re[i][j]);
            printf("\n");
        }

        maxx=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)if(re[i][j]>maxx)maxx=re[i][j];
        }
        printf("%d\n",maxx);
    }
    return 0;
}
