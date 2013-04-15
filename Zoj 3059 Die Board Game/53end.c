#include<stdio.h>
#include<string.h>
int data[205][205];
int movex[4]={0,0,1,-1};
int movey[4]={1,-1,0,0};
int bfs[800000][6];
int dui[6];
int m,n;
int startx,starty,endx,endy,enddi,endqi;
int use[205][205][7][7];

int rolldi(int di,int qi,int yo,int x)
{
    if(x==0)return yo;
    else if(x==1)return dui[yo];
    else if(x==2)return qi;
    else return dui[qi];
	return 0;
}

int rollqi(int di,int qi,int yo,int x)
{
    if(x==0)return qi;
    else if(x==1)return qi;
    else if(x==2)return dui[di];
    else return di;
	return 0;
}

int rollyo(int di,int qi,int yo,int x)
{
    if(x==0)return dui[di];
    else if(x==1)return di;
    else if(x==2)return yo;
    else return yo;
	return 0;
}

int  main()
{
	int i,j,di,qi,yo,x,y,head,end,sign;
	char s[200];
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=1;i<=m;i++)
        {
            scanf("%s",s);
            for(j=1;j<=n;j++)
            {
                if(s[j-1]=='#')data[i][j]=1;
                else data[i][j]=0;
            }
        }

        scanf("%d%d%d%d",&startx,&starty,&endx,&endy);
        startx++;
        starty++;
        endx++;
        endy++;
        //printf("%d %d %d %d\n",startx,starty,endx,endy);
        for(i=1;i<=3;i++)
        {
            scanf("%d%d",&x,&y);
            dui[x]=y;
            dui[y]=x;
            if(i==1)di=y;
            else if(i==2)qi=y;
            else if(i==3)yo=y;
        }
        scanf("%d",&j);
        scanf("%d",&enddi);
        scanf("%d",&j);
        scanf("%d",&endqi);
        for(i=1;i<=2;i++)scanf("%d",&j);
        /*if(startx==endx&&starty==endy&&di==enddi&&qi==endqi)
        {
            if(m+n>2)printf("2\n");
            else printf("-1\n");
            continue;
        }*/
        if(data[startx][starty]==1)
        {
            printf("-1\n");
            continue;
        }
        //printf("%d %d %d %d %d\n",di,qi,yo,enddi,endqi);
        memset(use,0,sizeof(use));
        //use[startx][starty][di][qi]=1;
        head=0;
        end=1;
        bfs[head][0]=startx;
        bfs[head][1]=starty;
        bfs[head][2]=di;
        bfs[head][3]=qi;
        bfs[head][4]=yo;
        bfs[head][5]=0;
        sign=0;
        for(;head<end;)
        {
            for(i=0;i<=3;i++)
            {
                if(bfs[head][0]+movex[i]>=1&&bfs[head][0]+movex[i]<=m&&bfs[head][1]+movey[i]>=1&&bfs[head][1]+movey[i]<=n&&use[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]][rolldi(bfs[head][2],bfs[head][3],bfs[head][4],i)][rollqi(bfs[head][2],bfs[head][3],bfs[head][4],i)]==0&&data[bfs[head][0]+movex[i]][bfs[head][1]+movey[i]]==0)
                {
                    bfs[end][0]=bfs[head][0]+movex[i];
                    bfs[end][1]=bfs[head][1]+movey[i];
                    bfs[end][2]=rolldi(bfs[head][2],bfs[head][3],bfs[head][4],i);
                    bfs[end][3]=rollqi(bfs[head][2],bfs[head][3],bfs[head][4],i);
                    bfs[end][4]=rollyo(bfs[head][2],bfs[head][3],bfs[head][4],i);
                    bfs[end][5]=bfs[head][5]+1;
                    use[bfs[end][0]][bfs[end][1]][bfs[end][2]][bfs[end][3]]=1;
                    if(bfs[end][0]==endx&&bfs[end][1]==endy&&bfs[end][2]==enddi&&bfs[end][3]==endqi)
                    {
                        printf("%d\n",bfs[end][5]);
                        sign=1;
                        break;
                    }
                    end++;
                }
            }
            if(sign==1)break;
            head++;
        }
        if(sign==0)printf("-1\n");
       /* for(i=0;i<=end;i++)printf("%2d ",bfs[i][0]);
        printf("\n");
        for(i=0;i<=end;i++)printf("%2d ",bfs[i][1]);
        printf("\n");
        for(i=0;i<=end;i++)printf("%2d ",bfs[i][2]);
        printf("\n");
        for(i=0;i<=end;i++)printf("%2d ",bfs[i][3]);
        printf("\n");
        for(i=0;i<=end;i++)printf("%2d ",bfs[i][4]);
        printf("\n");
        for(i=0;i<=end;i++)printf("%2d ",bfs[i][5]);
        printf("\n");*/
        //if(sum==50000)printf("-1\n");
        //else printf("%d\n",sum-1);
    }
    return 0;
}
