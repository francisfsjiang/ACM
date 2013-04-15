#include<stdio.h>
#include<string.h>
int data[105][105];
int movex[4]={0,0,1,-1};
int movey[4]={1,-1,0,0};
int dui[6];
int m,n;
int sum;
int startx,starty,endx,endy,enddi,endqi;
int use[105][105][7][7];

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

void search(int x,int y,int di,int qi,int yo,int step)
{
    //printf("%d %d %d %d %d %d\n",x,y,di,qi,yo,step);
    if(use[x][y][di][qi]!=0&&use[x][y][di][qi]<step)return;
    if(x==endx&&y==endy&&di==enddi&&qi==endqi&&step<sum)
    {
            sum=step;
            printf("---------%d %d %d %d %d %d\n",x,y,di,qi,yo,step);
    }
        //printf("search--------%d %d %d %d %d %d\n",x,y,di,qi,yo,step);
        int i;
        use[x][y][di][qi]=step;
        for(i=0;i<=3;i++)
        {
            if(x+movex[i]>=1&&x+movex[i]<=m&&y+movey[i]>=1&&y+movey[i]<=n&&data[x+movex[i]][y+movey[i]]==0)
            {
                search(x+movex[i],y+movey[i],rolldi(di,qi,yo,i),rollqi(di,qi,yo,i),rollyo(di,qi,yo,i),step+1);
            }
        }
}

int  main()
{
	int i,j,di,qi,yo,x,y;
	char s[105];
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    /*void search(int x,int y,int di,int qi,int yo,int step);
    int rolldi(int di,int qi,int yo,int x);
    int rollqi(int di,int qi,int yo,int x);
    int rollyo(int di,int qi,int yo,int x);*/
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
        /*sum=0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {   sum++;
                printf("%d ",data[i][j]);
            }
            printf("%d\n",sum);
        }
        printf("%d\n",sum);*/

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
        scanf("%d",&di);
        for(i=1;i<=2;i++)scanf("%d",&j);
        scanf("%d",&qi);
        for(i=1;i<=2;i++)scanf("%d",&j);
        scanf("%d",&j);
        scanf("%d",&enddi);
        scanf("%d",&j);
        scanf("%d",&endqi);
        for(i=1;i<=2;i++)scanf("%d",&j);
        if(startx==endx&&starty==endy&&di==enddi&&qi==endqi)
        {
            if(m+n>2)printf("2\n");
            else printf("-1\n");
            continue;
        }
        if(data[startx][starty]==1)
        {
            printf("-1\n");
            continue;
        }
        //printf("%d %d %d %d %d\n",di,qi,yo,enddi,endqi);
        memset(use,0,sizeof(use));
        sum=50000;
        //use[startx][starty][di][qi]=1;
        search(startx,starty,di,qi,yo,1);
        if(sum==50000)printf("-1\n");
        else printf("%d\n",sum-1);
    }
    return 0;
}
