#include<stdio.h>
int dp[7000][2];//存储以当前节点为根的子树的最大欢乐值，0不取根，1取根
int used[7000];//判断
int child[7000];//第一个子节点
int childn[7000];//子节点数量
int brother[7000];//兄弟节点
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int down(int x);//递归函数
    int max(int x,int y);
    int n,i,x,y,kid,maxx;
    for(;scanf("%d",&n)==1;)
    {
         memset(dp,0,sizeof(dp));//初始化，编译不过可以用循环初始化
         memset(used,0,sizeof(used));
         memset(child,0,sizeof(child));
         memset(childn,0,sizeof(childn));
         memset(brother,0,sizeof(brother));
         for(i=1;i<=n;i++)scanf("%d",&dp[i][1]);
         for(;;)//input
         {
                scanf("%d%d",&x,&y);
                if(x==0||y==0)break;
                used[x]=1;
                if(childn[y]==0)
                {
                                childn[y]=1;
                                child[y]=x;
                }
                else
                {
                    kid=child[y];
                    for(i=1;i<childn[y];i++)
                    {
                                            kid=brother[kid];
                    }
                    brother[kid]=x;
                    childn[y]++;
                }
         }
                for(i=1;i<=n;i++)if(used[i]==0)//找到根节点
                {
                        down(i);
                        break;
                }
                maxx=0;
                for(i=1;i<=n;i++)if(dp[i][0]>maxx)maxx=dp[i][0];//找到最大欢乐值，其实不用-_-!
                for(i=1;i<=n;i++)if(dp[i][1]>maxx)maxx=dp[i][1];
                printf("%d\n",maxx);
    }
    return 0;
}


int down(int x)
{
    int i,kid;
    kid=child[x];
    for(i=0;i<childn[x];i++)//每个子节点依次递归
    {
          down(kid);
          dp[x][1]+=dp[kid][0];
          dp[x][0]+=max(dp[kid][0],dp[kid][1]);
          kid=brother[kid];
    }
}

int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}
