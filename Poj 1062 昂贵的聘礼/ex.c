#include<stdio.h>
#define MAX 105
int level[MAX];
int price[MAX];
int data[MAX][MAX]={0};
int cost[MAX];
int in[MAX];
int spfa[500000];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,x,y,up,down,m,n,head,end,temp;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&price[i],&level[i],&k);
        for(;k>0;k--)
        {
            scanf("%d",&x);
            scanf("%d",&data[i][x]);
        }
    }
    int min=price[1];
    for(down=level[1]-m;down<=level[1];down++)
    {
        up=down+m;
        //printf("%d %d ---------\n",up,down);
        for(i=1;i<=n;i++)cost[i]=99999999;
        cost[1]=price[1];
        head=0;
        end=1;
        in[1]=1;
        spfa[0]=1;
        while(head<end)
        {
            for(i=1;i<=n;i++)
            {
                temp=cost[spfa[head]]-price[spfa[head]]+data[spfa[head]][i]+price[i];
                if(data[spfa[head]][i]&&temp<cost[i]&&level[i]<=up&&level[i]>=down)
                {
                    cost[i]=temp;
                    if(cost[i]<min)min=cost[i];
                    if(!in[i])
                    {
                        in[i]=1;
                        spfa[end]=i;
                        end++;
                    }
                }
            }
            in[spfa[head]]=0;
            head++;
        }
    }
    printf("%d\n",min);
    return 0;
}
