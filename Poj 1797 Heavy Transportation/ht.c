#include<stdio.h>
int data[1005][1005];//邻接表
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,m,n,i,j,k,end,x,y,min,minn;
    int spfa[10000];
    int result[1005];
    int list[1005];
    int XXOO(int x,int y);
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
                    scanf("%d%d",&n,&m);
                    memset(data,0,sizeof(data));
                    memset(result,0,sizeof(result));
                    memset(list,0,sizeof(list));
                    for(j=0;j<m;j++)
                    {
                                    scanf("%d%d",&x,&y);
                                    scanf("%d",&data[x][y]);
                                    data[y][x]=data[x][y];
                    }
                    list[1]=1;
                    result[1]=1000000;
                    minn=1;
                    end=1;
                    for(;end<n;)//SPFA
                    {
                           for(j=1;j<=n;j++)
                           {
                                            if(data[minn][j]!=0&&list[minn]!=j)
                                            {
                                                                                   if(data[minn][j]>result[j]&&result[minn]>result[j])
                                                                                   result[j]=XXOO(data[minn][j],result[minn]);
                                            }
                           }
                           min=0;
                           for(j=1;j<=n;j++)
                           {
                                             if(list[j]!=1&&result[j]>min)
                                             {
                                                                          min=result[j];
                                                                          minn=j;
                                             }
                           }
                           list[minn]=1;
                           end++;
                    }
                    printf("Scenario #%d:\n%d\n\n",i+1,result[n]);
    }
    return 0;
}

int XXOO(int x,int y)
{
    if(x<y)return x;
    else return y;
}
