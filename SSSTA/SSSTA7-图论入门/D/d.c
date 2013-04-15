# include<stdio.h>
# include<stdlib.h>
# include<string.h>
int map[2005][2005];
int lowcase[2005];
int in[2005];
char s[2005][10];

int cmp(int x,int y)
{
    int temp=0,i;
    for(i=0;i<7;i++)if(s[x][i]!=s[y][i])temp++;
    return temp;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,n,sum,min,minn,edges,temp;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(i=0;i<n;i++)lowcase[i]=9999999;
        memset(in,0,sizeof(in));
        memset(map,-1,sizeof(map));
        edges=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for(i=0;i<n;i++)for(j=i+1;j<n;j++)
        {
            temp=cmp(i,j);
            map[i][j]=map[j][i]=temp;
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)printf("%d ",map[i][j]);
            printf("\n");
        }*/
        in[0]=1;
        for(i=1;i<n;i++)lowcase[i]=map[0][i];
        /*for(j=0;j<n;j++)printf("%d ",lowcase[j]);
        printf("\n");*/
        sum=0;
        for(i=0;i<n;i++)
        {
            min=9999999;
            minn=-1;
            for(j=0;j<n;j++)if(lowcase[j]<min)
            {
                min=lowcase[j];
                minn=j;
            }
            if(minn==-1)break;
            //printf("%d %d\n",min,minn);
            sum+=min;
            lowcase[minn]=9999999;
            in[minn]=1;
            for(j=0;j<n;j++)if(map[minn][j]!=-1&&in[j]==0&&map[minn][j]<lowcase[j])lowcase[j]=map[minn][j];
                /*for(j=0;j<n;j++)printf("%d ",lowcase[j]);
                printf("\n");*/
        }
        printf("The highest possible quality is 1/%d.\n",sum);
    }
    return 0;
}
