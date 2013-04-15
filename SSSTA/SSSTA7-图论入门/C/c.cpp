# include<stdio.h>
# include<stdlib.h>
# include<string.h>
int edge[300005][3];
int in[300005];
int used[300005];
int fath[2000];
int edges,n,m;
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

int mst()
{
    memset(fath,-1,sizeof(fath));
    int sum,i,sumn,x,y;
    sumn=0;
    sum=0;
    for(i=0;i<edges;i++)
    {
        if(used[i]==1)continue;
        x=fa(edge[i][0]);
        y=fa(edge[i][1]);
        if(x==y)continue;
        else
        {
            fath[y]=fath[x];
            sum+=edge[i][2];
            sumn++;
        }
    }
    if(sumn!=n-1)return -1;
    else return sum;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,temp,head,sum,x,y;
    char s[5];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        memset(used,0,sizeof(used));
        memset(in,0,sizeof(in));
        for(i=0;i<m;i++)
        {
                scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
        }
        edges=m;
        //for(i=0;i<edges;i++)printf("%d %d %d\n",edge[i][0],edge[i][1],edge[i][2]);
        qs(0,edges-1);
        //for(i=0;i<edges;i++)printf("%d %d %d\n",edge[i][0],edge[i][1],edge[i][2]);
        memset(fath,-1,sizeof(fath));
        sum=0;
        for(i=0;i<edges;i++)
        {
            x=fa(edge[i][0]);
            y=fa(edge[i][1]);
            if(x==y)continue;
            else
            {
                fath[y]=fath[x];
                sum+=edge[i][2];
                in[i]=1;
            }
        }
        //printf("sum=%d\n",sum);
        for(i=0;i<edges;i++)
        {
            if(in[i]==1)
            {
                used[i]=1;
                temp=mst();
                //printf("temp=%d\n",temp);
                if(temp==sum)
                {
                    printf("Not Unique!\n");
                    break;
                }
                used[i]=0;
            }
        }
        if(i==edges)printf("%d\n",sum);
    }
    return 0;
}

