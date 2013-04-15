#include<stdio.h>
int movex[4]={1,-1,0,0};
int movey[4]={0,0,1,-1};
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int data[6][6],bfs[100][3]={0},in[6][6]={0};
    int i,j;
    for(i=0;i<5;i++)for(j=0;j<5;j++)scanf("%d",&data[i][j]);
    /*for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)printf("%d",data[i][j]);
        printf("\n");
    }*/
    int head=0,end=1;
    bfs[head][0]=0;
    bfs[head][1]=0;
    bfs[head][2]=-1;
    in[0][0]=1;
    for(;head<end;)
    {
        for(i=0;i<=3;i++)
        {
            if(bfs[head][0]+movex[i]>=0&&bfs[head][0]+movex[i]<5&&bfs[head][1]+movey[i]>=0&&bfs[head][1]+movey[i]<5&&in[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]]==0&&data[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]]==0)
            {
                bfs[end][0]=bfs[head][0]+movex[i];
                bfs[end][1]=bfs[head][1]+movey[i];
                bfs[end][2]=head;
                in[bfs[end][0]][bfs[end][1]]=1;
                //printf("%d %d %d\n",bfs[end][0],bfs[end][1],bfs[end][2]);
                if(bfs[end][0]==4&&bfs[end][1]==4)
                {
                    head=end;
                    break;
                }
                else end++;
            }
        }
        head++;
    }
    int now=end;
    int out[100];
    for(i=1;i<=25&&now!=-1;i++)
    {
        //printf("%d %d\n",bfs[now][0],bfs[now][1]);
        out[i]=now;
        now=bfs[now][2];
    }
    for(j=i-1;j>=1;j--)printf("(%d, %d)\n",bfs[out[j]][0],bfs[out[j]][1]);
    return 0;
}
