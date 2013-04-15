# include<stdio.h>
# include<stdlib.h>
# include<string.h>
#include<math.h>
int edge[3000][2];
double dist[3000];
int pos[50][2];
int fath[50];
int fa(int x)
{
    if(fath[x]==-1)
    {
        fath[x]=x;
        return fath[x];
    }
    else if(fath[x]==x)return x;
    else
    {
        fath[x]=fa(fath[x]);
        return fath[x];
    }
}

int exchange(int x,int y)
{
    int temp;
    temp=edge[x][0];
    edge[x][0]=edge[y][0];
    edge[y][0]=temp;
    temp=edge[x][1];
    edge[x][1]=edge[y][1];
    edge[y][1]=temp;
    double temp2=dist[x];
    dist[x]=dist[y];
    dist[y]=temp2;
}

int qs(int s,int t)
{
     int i,j,temp,m;
     double y;
     m=rand()%(t-s+1)+s;
     exchange(m,s);
     i=s;
     j=t+1;
     y=dist[s];
     for(;i<j;)
     {
                 for(i++;dist[i]<y;i++);
                 for(j--;dist[j]>y;j--);
                 if(i<j)
                 {
                        exchange(i,j);
                 }
     }
     exchange(s,j);
     if(s<j-1)qs(s,j-1);
     if(j+1<t)qs(j+1,t);
}


int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,n,m,temp,head,edges,x,y,apple,nike;
    double sum;
    char s[5];
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        memset(fath,-1,sizeof(fath));
        edges=0;
        scanf("%d%d",&apple,&nike);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&pos[i][0],&pos[i][1]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j==i)continue;
                else
                {
                    edge[edges][0]=i;
                    edge[edges][1]=j;
                    dist[edges]=sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
                    edges++;
                }
            }
        }
        //for(i=0;i<edges;i++)printf("%d %d %lf\n",edge[i][0],edge[i][1],dist[i]);
        qs(0,edges-1);
        //for(i=0;i<edges;i++)printf("%d %d %lf\n",edge[i][0],edge[i][1],dist[i]);
        apple--;
        nike--;
        sum=sqrt((pos[apple][0]-pos[nike][0])*(pos[apple][0]-pos[nike][0])+(pos[apple][1]-pos[nike][1])*(pos[apple][1]-pos[nike][1]));
        fath[apple]=apple;
        fath[nike]=apple;
        for(i=0;i<edges;i++)
        {
            x=fa(edge[i][0]);
            y=fa(edge[i][1]);
            //printf("%d %d\n",x,y);
            if(x==y)continue;
            else
            {
                fath[y]=fath[x];
                sum+=dist[i];
            }
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
