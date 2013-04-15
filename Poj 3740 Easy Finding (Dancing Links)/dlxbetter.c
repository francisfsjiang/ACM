#include<stdio.h>
#include<string.h>
#define MAX 50000
int m,n;
int dlxup[MAX];
int dlxdown[MAX];
int dlxleft[MAX];
int dlxright[MAX];
int dlxcloumn[MAX];
int dlxs[MAX];
int last[MAX];
int head[MAX];
int ans[MAX];

void insert(int x,int y,int sign)
{
    //printf("%d %d\n",x,y);
    if(!head[x])
    {
        head[x]=sign;
        last[x]=sign;
    }
    else
    {
        dlxright[last[x]]=sign;
        dlxleft[sign]=last[x];
        last[x]=sign;
    }
    dlxdown[dlxup[y]]=sign;
    dlxup[sign]=dlxup[y];
    dlxup[y]=sign;
    dlxs[y]++;
    dlxcloumn[sign]=y;
}

void makeup()
{
        int i,j,x,y,z,sign;
        for(i=1;i<=n;i++)
        {
            dlxleft[i]=i-1;
            dlxright[i]=i+1;
            dlxup[i]=i;
            dlxdown[i]=i;
            dlxcloumn[i]=i;
        }
        dlxleft[0]=n;
        dlxright[0]=1;
        dlxright[n]=0;
        dlxs[0]=n;
        sign=n;
        for(i=1;i<=m;i++)for(j=1;j<=n;j++)
        {
            scanf("%d",&z);
            if(z)
            {
                sign++;
                insert(i,j,sign);
            }
        }
        for(i=1;i<=n;i++)dlxdown[dlxup[i]]=i;
        for(i=1;i<=m;i++)
        {
            if(last[i]!=0)
            {
                dlxright[last[i]]=head[i];
                dlxleft[head[i]]=last[i];
            }
        }
        /*for(i=0;i<=sign;i++)printf("%2d ",i);
        printf("\n");
        for(i=0;i<=sign;i++)printf("%2d ",dlxup[i]);
        printf("\n");
        for(i=0;i<=sign;i++)printf("%2d ",dlxdown[i]);
        printf("\n");
        for(i=0;i<=sign;i++)printf("%2d ",dlxleft[i]);
        printf("\n");
        for(i=0;i<=sign;i++)printf("%2d ",dlxright[i]);
        printf("\n");
        for(i=0;i<=sign;i++)printf("%2d ",dlxcloumn[i]);
        printf("\n");
        for(i=0;i<=sign;i++)printf("%2d ",dlxs[i]);
        printf("\n");*/
}

void removec(int x)
{
    int i,j;
    dlxs[0]--;
    dlxright[dlxleft[x]]=dlxright[x];
    dlxleft[dlxright[x]]=dlxleft[x];
    for(i=dlxdown[x];i!=x;i=dlxdown[i])for(j=dlxright[i];j!=i;j=dlxright[j])
    {
        dlxup[dlxdown[j]]=dlxup[j];
        dlxdown[dlxup[j]]=dlxdown[j];
        dlxs[dlxcloumn[j]]--;
    }
}

void resumec(int x)
{
    int i,j;
    dlxs[0]++;
    for(i=dlxup[x];i!=x;i=dlxup[i])for(j=dlxleft[i];j!=i;j=dlxleft[j])
    {
        dlxup[dlxdown[j]]=j;
        dlxdown[dlxup[j]]=j;
        dlxs[dlxcloumn[j]]++;
    }
    dlxright[dlxleft[x]]=x;
    dlxleft[dlxright[x]]=x;
}

int dance(int x)
{
    if(dlxright[0]==0)
    {
        return 1;
    }
    else
    {
        int min=999999,minn,i,j;
        for(i=dlxright[0];i!=0;i=dlxright[i])if(dlxs[i]<min)
        {
            min=dlxs[i];
            minn=i;
        }
        removec(minn);
        for(i=dlxdown[minn];i!=minn;i=dlxdown[i])
        {
            ans[x]=minn;
            for(j=dlxright[i];j!=i;j=dlxright[j])removec(dlxcloumn[j]);
            if(dance(x+1))return 1;
            for(j=dlxleft[i];j!=i;j=dlxleft[j])resumec(dlxcloumn[j]);
        }
        resumec(minn);
        return 0;
    }
}

int main()
{
    int i,j;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(dlxs,0,sizeof(dlxs));
        memset(ans,0,sizeof(ans));
        memset(last,0,sizeof(last));
        memset(head,0,sizeof(head));
        makeup();
        if(dance(0))
        {
            printf("Yes, I found it\n");
        }
        else printf("It is impossible\n");
    }
    return 0;
}
