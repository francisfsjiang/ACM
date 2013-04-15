#include<stdio.h>
#include<string.h>
int m,n;
int data[25][25];
int used[25][25];
int movex[4]={0,0,-1,1};
int movey[4]={1,-1,0,0};
int startx,starty;
int sum;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int search(int x,int y);
    char s[30];
    int i,j;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(n==0)break;
        memset(used,0,sizeof(used));
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            for(j=1;j<=m;j++)
            {
                if(s[j-1]=='.')data[i][j]=0;
                else if(s[j-1]=='#')data[i][j]=1;
                else
                {
                    startx=i;
                    starty=j;
                    data[i][j]=1;
                }
            }
        }
        //used[startx][starty]=1;
        sum=1;
        search(startx,starty);
        printf("%d\n",sum);
    }
    return 0;
}

int search(int x,int y)
{
    int i;
    for(i=0;i<=3;i++)
    {
        if(x+movex[i]>=1&&x+movex[i]<=n&&y+movey[i]>=1&&y+movey[i]<=m&&data[x+movex[i]][y+movey[i]]==0)
        {
            data[x+movex[i]][y+movey[i]]=1;
            sum++;
            search(x+movex[i],y+movey[i]);
        }
    }
}

