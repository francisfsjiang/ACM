# include<stdio.h>
# include<stdlib.h>
# include<string.h>
#include<math.h>
int edge[500000][2];
double dist[500000];
int pos[505][2];
int fath[505];
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

void exchange(int x,int y)
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

void qs(int s,int t)
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
    int i,j,n,edges,x,y;
    double sum;
    int sumn;
    int t,s,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&s,&n);
        memset(fath,-1,sizeof(fath));
        edges=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&pos[i][0],&pos[i][1]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(j==i)continue;
                else
                {
                    edge[edges][0]=i;
                    edge[edges][1]=j;
                    dist[edges]=sqrt((double)(pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
                    edges++;
                }
            }
        }
        //for(i=0;i<edges;i++)printf("%d %d %lf\n",edge[i][0],edge[i][1],dist[i]);
        qs(0,edges-1);
        //for(i=0;i<edges;i++)printf("%d %d %lf\n",edge[i][0],edge[i][1],dist[i]);
        sum=0;
        sumn=0;
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
                sumn++;
                if(sumn==n-s)
                {
                    printf("%.2lf\n",dist[i]);
                    break;
                 }
            }
        }
    }
    return 0;
}
