#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int num[MAX];
int numi[MAX];
int numj[MAX];
int lastc;
char str[10];
int nine[10][10]=
{
{0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9}};

void record(int x,int y,int sign,int numb)
{
    num[sign]=numb;
    numi[sign]=x;
    numj[sign]=y;
}

void insert(int x,int y,int sign)
{
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
        int i,j,k,x,sign;
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
        lastc=1;
        for(i=1;i<=9;i++)
{
        scanf("%s",str);
        for(j=1;j<=9;j++)
        {
            x=str[j-1]-48;
            if(x)
            {
                sign++;
                insert(lastc,(i-1)*9+j,sign);
                record(i,j,sign,x);
                sign++;
                insert(lastc,81+(i-1)*9+x,sign);
                record(i,j,sign,x);
                sign++;
                insert(lastc,162+(j-1)*9+x,sign);
                record(i,j,sign,x);
                sign++;
                insert(lastc,243+(nine[i][j]-1)*9+x,sign);
                record(i,j,sign,x);
                lastc++;
            }
            else
            {
                for(k=1;k<=9;k++)
                {
                    sign++;
                    insert(lastc,(i-1)*9+j,sign);
                    record(i,j,sign,k);
                    sign++;
                    insert(lastc,81+(i-1)*9+k,sign);
                    record(i,j,sign,k);
                    sign++;
                    insert(lastc,162+(j-1)*9+k,sign);
                    record(i,j,sign,k);
                    sign++;
                    insert(lastc,243+(nine[i][j]-1)*9+k,sign);
                    record(i,j,sign,k);
                    lastc++;
                }
            }
        }
}
        for(i=1;i<=n;i++)dlxdown[dlxup[i]]=i;
        for(i=1;i<=lastc;i++)
        {
            if(last[i]!=0)
            {
                dlxright[last[i]]=head[i];
                dlxleft[head[i]]=last[i];
            }
        }
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
            ans[x]=i;
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
    int i,j,t;
    int sudo[10][10];
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    n=324;
    while(t--)
    {
        memset(dlxs,0,sizeof(dlxs));
        memset(ans,0,sizeof(ans));
        memset(last,0,sizeof(last));
        memset(head,0,sizeof(head));
        makeup();
        if(dance(0))
        {
            for(i=0;i<81;i++)
            {
                sudo[numi[ans[i]]][numj[ans[i]]]=num[ans[i]];
            }
            for(i=1;i<=9;i++)
            {
                for(j=1;j<=9;j++)printf("%d",sudo[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
