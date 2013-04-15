#include<stdio.h>
#include<string.h>
#define MAX 510
int data[MAX][MAX];
int time[MAX];
int use[MAX];
int in[MAX];
int spfa[2000000];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,m,n,w,i,j,x,y,sign,head,end,z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&w);
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)data[i][j]=9999999;
        for(i=1;i<=n;i++)time[i]=9999999;
        memset(use,0,sizeof(use));
        memset(in,0,sizeof(in));
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(z<data[x][y])
            {
                data[x][y]=z;
                data[y][x]=z;
            }
        }
        for(i=0;i<w;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(data[x][y]==9999999||-data[x][y]<z)
            {
                data[x][y]=-z;
            }
        }
        head=0;
        end=1;
        spfa[head]=1;
        time[1]=0;
        in[1]=1;
        sign=0;
        while(head<end)
        {
            for(i=1;i<=n;i++)
            {
                if(time[spfa[head]]+data[spfa[head]][i]<time[i])
                {
                    time[i]=time[spfa[head]]+data[spfa[head]][i];
                    if(in[i]==0)
                    {
                        spfa[end]=i;
                        in[i]=1;
                        end++;
                        use[i]++;
                        if(use[i]>n+2)
                        {
                            sign=1;
                            break;
                        }
                    }

                    /*for(j=1;j<=n;j++)printf("%d ",time[j]);
                    printf("\n");*/
                }
            }
            if(sign==1)break;
            in[spfa[head]]=0;
            head++;
        }
        if(sign==1)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
