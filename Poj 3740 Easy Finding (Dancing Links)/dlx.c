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
int data[17][1005];
int num[17][1005];
int ans[MAX];
int sign;
int main()
{
    int i,j,last,head;
    int check(int data[],int n);
    void makeup();
    int removec(int x);
    int resumec(int x);
    int dance(int x);
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(dlxs,0,sizeof(dlxs));
        memset(ans,0,sizeof(ans));
        sign=n+1;
        for(i=1;i<=m;i++)for(j=1;j<=n;j++)
        {
            scanf("%d",&data[i][j]);
            if(data[i][j]==1)
            {
                num[i][j]=sign;
                dlxcloumn[sign]=j;
                dlxs[j]++;
                sign++;
            }
        }
        makeup();
        if(dance(0))
        {
            printf("Yes, I found it\n");
            /*for(i=0;i<=m;i++)
            {
                printf("%d  ",ans[i]);
            }*/
        }
        else printf("It is impossible\n");
    }
    return 0;
}

int check(int data[],int n)
{
    int i;
    for(i=0;i<n;i++)printf("%2d ",data[i]);
    printf("\n");
}

void makeup()
{
        int last,head,i,j;
        dlxup[0]=0;
        dlxdown[0]=0;
        dlxcloumn[0]=0;
        dlxs[0]=n;
        last=0;
        for(i=1;i<=n;i++)
        {
            dlxright[last]=i;
            dlxleft[i]=last;
            last=i;
            dlxcloumn[i]=i;
        }
        dlxright[n]=0;
        dlxleft[0]=n;
        for(i=1;i<=m;i++)
        {
            last=0;
            for(j=1;j<=n;j++)if(data[i][j]==1)
            {
                if(last==0)
                {
                    head=num[i][j];
                    last=num[i][j];
                }
                else
                {
                    dlxleft[num[i][j]]=last;
                    dlxright[last]=num[i][j];
                    last=num[i][j];
                }
            }
            if(last!=0)
            {
                dlxright[last]=head;
                dlxleft[head]=last;
            }
        }
        for(j=1;j<=n;j++)
        {
            last=j;
            for(i=1;i<=m;i++)if(data[i][j]==1)
            {
                dlxup[num[i][j]]=last;
                dlxdown[last]=num[i][j];
                last=num[i][j];
            }
            dlxdown[last]=j;
            dlxup[j]=last;
        }
}

int removec(int x)
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

int resumec(int x)
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
