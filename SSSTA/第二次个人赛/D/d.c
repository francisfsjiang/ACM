#include<stdio.h>
#include<string.h>
int movex[8]={-2,-1,1,2,2,1,-1,-2};
int movey[8]={1,2,2,1,-1,-2,-2,-1};
int used[305][305];
int bfsx[800000];
int bfsy[800000];
int bfsn[800000];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,i,sign,n,startx,starty,endx,endy,nowx,nowy,head,end;
    scanf("%d",&t);
    while(t--)
    {
        memset(used,0,sizeof(used));
        scanf("%d",&n);
        scanf("%d%d",&startx,&starty);
        scanf("%d%d",&endx,&endy);
        if(startx==endx&&starty==endy)
        {
            printf("0\n");
            continue;
        }
        head=0;
        bfsx[head]=startx;
        bfsy[head]=starty;
        bfsn[head]=0;
        end=1;
        sign=0;
        while(head<end)
        {
            nowx=bfsx[head];
            nowy=bfsy[head];
            for(i=0;i<8;i++)
            {
                if(nowx+movex[i]>=0&&nowx+movex[i]<n&&nowy+movey[i]>=0&&nowy+movey[i]<n
                    &&used[nowx+movex[i]][nowy+movey[i]]==0)
                {
                    bfsx[end]=nowx+movex[i];
                    bfsy[end]=nowy+movey[i];
                    bfsn[end]=bfsn[head]+1;
                    used[nowx+movex[i]][nowy+movey[i]]=1;
                    if(bfsx[end]==endx&&bfsy[end]==endy)
                    {
                        sign=1;
                        break;
                    }
                    end++;
                }
            }
            if(sign==1)break;
            head++;
        }
        /*for(i=0;i<=end;i++)printf("%d ",bfsx[i]);
        printf("\n");
        for(i=0;i<=end;i++)printf("%d ",bfsy[i]);
        printf("\n");
        for(i=0;i<=end;i++)printf("%d ",bfsn[i]);
        printf("\n");*/
        printf("%d\n",bfsn[end]);
    }
    return 0;
}
