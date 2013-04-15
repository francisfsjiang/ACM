# include<stdio.h>
# include<stdlib.h>
# include<string.h>
int edge[10005][3];
int data[105][105];
int fath[105];
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
    temp=edge[x][2];
    edge[x][2]=edge[y][2];
    edge[y][2]=temp;
}

int qs(int s,int t)
{
     int i,j,y,temp,m;
     m=rand()%(t-s+1)+s;
     exchange(m,s);
     i=s;
     j=t+1;
     y=edge[s][2];
     for(;i<j;)
     {
                 for(i++;edge[i][2]<y;i++);
                 for(j--;edge[j][2]>y;j--);
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
    int i,j,n,m,temp,head,edges,sum,x,y;
        scanf("%d",&n);
        memset(fath,-1,sizeof(fath));
        edges=0;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)
        {
            scanf("%d",&data[i][j]);
            if(i>=1&&j<i)
            {
                edge[edges][0]=i;
                edge[edges][1]=j;
                edge[edges][2]=data[i][j];
                edges++;
            }
        }
        //for(i=0;i<edges;i++)printf("%d %d %d\n",edge[i][0],edge[i][1],edge[i][2]);
        qs(0,edges-1);
        //for(i=0;i<edges;i++)printf("%d %d %d\n",edge[i][0],edge[i][1],edge[i][2]);
        sum=0;
        int q;
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            x=fa(x);
            y=fa(y);
            fath[y]=fath[x];
        }
        for(i=0;i<edges;i++)
        {
            x=fa(edge[i][0]);
            y=fa(edge[i][1]);
            //printf("%d %d\n",x,y);
            if(x==y)continue;
            else
            {
                fath[y]=fath[x];
                sum+=edge[i][2];
            }
        }
        printf("%d\n",sum);
    return 0;
}
