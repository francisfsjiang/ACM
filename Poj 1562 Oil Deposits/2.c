#include<stdio.h>
int data[102][102];
//int used[102][102];
int movex[8]={0,0,-1,1,1,-1,1,-1};
int movey[8]={1,-1,0,0,1,-1,-1,1};
int m,n;
int sum;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j;
    int search(int x,int y);
    char temp[102];
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==0)break;
        sum=0;
        for(i=1;i<=m;i++)
        {
            scanf("%s",temp);
            for(j=1;j<=n;j++)
            {
                if(temp[j-1]=='@')data[i][j]=1;
                else data[i][j]=0;
            }
        }
        for(i=1;i<=m;i++)for(j=1;j<=n;j++)if(data[i][j]==1)
        {
            sum++;
            data[i][j]=0;
            search(i,j);
        }
        printf("%d\n",sum);
    }
    return 0;
}

int search(int x,int y)
{
    int i;
    for(i=0;i<=7;i++)
    {
        if(x+movex[i]>=1&&x+movex[i]<=m&&y+movey[i]>=1&&y+movey[i]<=n&&data[x+movex[i]][y+movey[i]]==1)
        {
            data[x+movex[i]][y+movey[i]]=0;
            search(x+movex[i],y+movey[i]);
        }
    }
}
