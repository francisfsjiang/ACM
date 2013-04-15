#include<stdio.h>
int data[205][205];
int result[205][205];
int used[205][205];
int movex[4]={1,-1,0,0};
int movey[4]={0,0,1,-1};
int m,n;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int search(int x,int y,int s,int sign);
    int bfs[40005][3];
    int startyx,startyy,startmx,startmy;
    int i,j,min,head,end;
    char s[205];
while(scanf("%d%d",&m,&n)!=EOF)
{
    if(m==0)break;
    for(i=1;i<=m;i++)for(j=1;j<=n;j++)result[i][j]=0;
    for(i=1;i<=m;i++)
    {
        scanf("%s",s);
        for(j=1;j<=n;j++)
        {
            if(s[j-1]=='#')data[i][j]=1;
            else if(s[j-1]=='.')data[i][j]=0;
            else if(s[j-1]=='@')data[i][j]=2;
            else if(s[j-1]=='Y')
            {
                startyx=i;
                startyy=j;
                data[i][j]=0;
            }
            else
            {
                startmx=i;
                startmy=j;
                data[i][j]=0;
            }
        }
    }
    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)printf("%d ",data[i][j]);
        printf("\n");
    }
    printf("\n");*/

    for(i=1;i<=m;i++)for(j=1;j<=n;j++)used[i][j]=0;
    used[startyx][startyy]=1;
    head=0;
    end=1;
    bfs[head][0]=startyx;
    bfs[head][1]=startyy;
    bfs[head][2]=0;
    for(;head<end;)
    {
        for(i=0;i<=3;i++)
        {
            if(bfs[head][0]+movex[i]>=1&&bfs[head][0]+movex[i]<=m&&bfs[head][1]+movey[i]>=1&&bfs[head][1]+movey[i]<=n&&used[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]]==0&&data[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]]!=1)
            {
                bfs[end][0]=bfs[head][0]+movex[i];
                bfs[end][1]=bfs[head][1]+movey[i];
                bfs[end][2]=bfs[head][2]+1;
                used[bfs[end][0]][bfs[end][1]]=1;
                //printf("%d %d %d\n",bfs[end][0],bfs[end][1],bfs[end][2]);
                //if(data[bfs[end][0]][bfs[end][1]]==2)
                //{
                    result[bfs[end][0]][bfs[end][1]]+=bfs[end][2];
                //}
                end++;
            }
        }
        head++;
    }

    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)printf("%d ",result[i][j]);
        printf("\n");
    }
    printf("\n");*/


    for(i=1;i<=m;i++)for(j=1;j<=n;j++)used[i][j]=0;
    used[startmx][startmy]=1;
    head=0;
    end=1;
    bfs[head][0]=startmx;
    bfs[head][1]=startmy;
    bfs[head][2]=0;
    for(;head<end;)
    {
        for(i=0;i<=3;i++)
        {
            if(bfs[head][0]+movex[i]>=1&&bfs[head][0]+movex[i]<=m&&bfs[head][1]+movey[i]>=1&&bfs[head][1]+movey[i]<=n&&used[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]]==0&&data[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]]!=1)
            {
                bfs[end][0]=bfs[head][0]+movex[i];
                bfs[end][1]=bfs[head][1]+movey[i];
                bfs[end][2]=bfs[head][2]+1;
                used[bfs[end][0]][bfs[end][1]]=1;
                //printf("%d %d %d\n",bfs[end][0],bfs[end][1],bfs[end][2]);
                //if(data[bfs[end][0]][bfs[end][1]]==2)
                //{
                    result[bfs[end][0]][bfs[end][1]]+=bfs[end][2];
                //}
                end++;
            }
        }
        head++;
    }

    /*for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)printf("%d ",result[i][j]);
        printf("\n");
    }*/
    min=10000;
    for(i=1;i<=m;i++)for(j=1;j<=n;j++)
    {
        if(data[i][j]==2&&result[i][j]<min&&result[i][j]!=0)
        {
            min=result[i][j];
        }
    }
    printf("%d\n",min*11);
}
    return 0;
}
