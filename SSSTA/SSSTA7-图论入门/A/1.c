# include<stdio.h>
# include<stdlib.h>
# include<string.h>
int edge[10005][3];
int fath[105];
int edges,n,max,min;
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
    temp=edge[x][2];
    edge[x][2]=edge[y][2];
    edge[y][2]=temp;
}

void qs(int s,int t)
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

int  mst(int q)
{
    memset(fath,-1,sizeof(fath));
    int sum,i,sumn,x,y;
    sumn=0;
    sum=0;
    for(i=q;i<edges;i++)
    {
        x=fa(edge[i][0]);
        y=fa(edge[i][1]);
        if(x==y)continue;
        else
        {
            fath[y]=fath[x];
            sum+=edge[i][2];
            sumn++;
            if(edge[i][2]>max)max=edge[i][2];
            if(edge[i][2]<min)min=edge[i][2];
        }
    }
    if(sumn!=n-1)return -1;
    else return sum;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,temp,head,sum,x,y,result,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0)break;
        if(m==0)
        {
            printf("-1\n");
            continue;
        }
        for(i=0;i<m;i++)
        {
                scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
        }
        edges=m;
        //for(i=0;i<edges;i++)printf("%d %d %d\n",edge[i][0],edge[i][1],edge[i][2]);
        qs(0,edges-1);
        //for(i=0;i<edges;i++)printf("%d %d %d\n",edge[i][0],edge[i][1],edge[i][2]);
        /*memset(fath,-1,sizeof(fath));
        max=-9999999;
        min=9999999;
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
                if(edge[i][2]>max)max=edge[i][2];
                if(edge[i][2]<min)min=edge[i][2];
            }
        }
        result=max-min;*/
        //printf("sum=%d\n",sum);
        result=9999999;
        for(i=0;i<edges;i++)
        {
                max=-9999999;
                min=9999999;
                temp=mst(i);
                //printf("temp=%d\n",temp);
                if(temp!=-1&&max-min<result)
                {
                    result=max-min;
                }
        }
        if(result==9999999)printf("-1\n");
        else printf("%d\n",result);
    }
    return 0;
}

