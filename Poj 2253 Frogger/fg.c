#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 205
int posx[MAX];
int posy[MAX];
int in[MAX];
int spfa[2000000];
double dist[MAX][MAX]={0};
double re[MAX];

double max(double x,double y)
{
    if(x>y)return x;
    else return y;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,t,head,end,n;
    for(t=1;;t++)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(i=1;i<=n;i++)scanf("%d%d",&posx[i],&posy[i]);
        for(i=1;i<=n;i++)for(j=1;j<i;j++)
        {
            dist[i][j]=sqrt((posx[i]-posx[j])*(posx[i]-posx[j])*1.0+(posy[i]-posy[j])*(posy[i]-posy[j]));
            dist[j][i]=dist[i][j];
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%lf ",dist[i][j]);
            printf("\n");
        }*/
        memset(in,0,sizeof(in));
        for(i=2;i<=n;i++)re[i]=99999999;
        re[1]=0;
        head=0;
        end=1;
        in[1]=1;
        spfa[head]=1;
        while(head<end)
        {
            for(i=1;i<=n;i++)
            {
                if(re[i]>max(re[spfa[head]],dist[spfa[head]][i]))
                {
                    re[i]=max(re[spfa[head]],dist[spfa[head]][i]);
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
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",t,re[2]);
    }
    return 0;
}
