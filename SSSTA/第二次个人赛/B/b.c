#include<stdio.h>
#include<string.h>
int data[305][305];
int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,n,m,t,x,y;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        memset(data,-1,sizeof(data));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            scanf("%d",&data[x][y]);
            //data[y][x]=data[x][y];
        }
        for(i=1;i<=n;i++)data[i][i]=0;
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%d ",data[i][j]);
            printf("\n");
        }*/
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(data[i][k]!=-1&&data[k][j]!=-1&&(data[i][j]==-1||data[i][j]>max(data[i][k],data[k][j])))
                    {
                        //printf("%d %d %d        %d\n",i,j,k,max(data[i][k],data[k][j]));
                        data[i][j]=max(data[i][k],data[k][j]);
                        //printf("%d %d %d \n",i,j,data[i][j]);
                    }
                }
            }
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%d ",data[i][j]);
            printf("\n");
        }*/
        for(i=0;i<t;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",data[x][y]);
        }
    }
    return 0;
}
