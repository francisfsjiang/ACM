#include<stdio.h>
#include<string.h>
int data[20][20];
int used[20][20][60];
int bfs[8000][3];
int m,n,t,sign;
int startx,starty,endx,endy;
int movex[4]={1,-1,0,0};
int movey[4]={0,0,-1,1};
int main()
{
    int i,j,k,head,end;
    char s;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(1)
    {
        scanf("%d%d%d",&m,&n,&t);
        if(m==0)
        {
            break;
        }
        scanf("%c",&s);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%c",&s);
                if(s==10)j--;
                else if(s=='.')data[i][j]=0;
                else if(s=='X')data[i][j]=1;
                else if(s=='S')
                {
                    startx=i;
                    starty=j;
                    data[i][j]=0;
                }
                else
                {
                    endx=i;
                    endy=j;
                    data[i][j]=0;
                }
            }
        }
        /*for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)printf("%d ",data[i][j]);
            printf("\n");
        }*/
        //printf("%d %d %d %d\n",startx,starty,endx,endy);
        for(i=0;i<m;i++)for(j=0;j<n;j++)for(k=0;k<=t;k++)used[i][j][k]=0;
        sign=0;
        head=0;
        end=1;
        used[startx][starty][0]=1;
        bfs[head][0]=startx;
        bfs[head][1]=starty;
        bfs[head][2]=0;
        for(;head<end;)
        {
            for(i=0;i<=3;i++)
            {
                if(bfs[head][2]+1<=t&&bfs[head][0]+movex[i]>=0&&bfs[head][0]+movex[i]<m&&bfs[head][1]+movey[i]>=0&&bfs[head][1]+movey[i]<n&&used[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]][bfs[head][2]+1]==0&&data[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]]!=1)
                {
                    bfs[end][0]=bfs[head][0]+movex[i];
                    bfs[end][1]=bfs[head][1]+movey[i];
                    bfs[end][2]=bfs[head][2]+1;
                    used[bfs[end][0]][bfs[end][1]][bfs[end][2]]=1;
                    if(bfs[end][0]==endx&&bfs[end][1]==endy&&bfs[end][2]==t)sign=1;
                    end++;
                }
            }
            if(sign==1)break;
            head++;
        }
        /*for(i=0;i<end;i++)printf("%d ",bfs[i][0]);
        printf("\n");
        for(i=0;i<end;i++)printf("%d ",bfs[i][1]);
        printf("\n");
        for(i=0;i<end;i++)printf("%d ",bfs[i][2]);
        printf("\n");*/
        if(sign==0)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
