#include<stdio.h>
#include<string.h>
int jump[400][400];
char temp[40];
char s[400];
int l;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int min(int x,int y);
    int max(int x,int y);
    int search(int start,int now,int sign,int len);
    int w,i,j,l2,k;
    int data[400];
    //int dp[30][305];
    //int dps[30][305];
    scanf("%d%d",&w,&l);
    scanf("%s",s);
    //printf("%s\n",s);
    //for(i=1;i<=l;i++)data[i]=i;
    /*for(j=1;j<=l;j++)printf("%d ",data[j]);
        printf("\n");*/
        memset(jump,0,sizeof(jump));
        //memset(data,-1,sizeof(data));
    for(i=1;i<=w;i++)
    {
        scanf("%s",temp);
        l2=strlen(temp);
        for(j=0;j<l;j++)if(temp[0]==s[j])search(j,j+1,1,l2);
    }
    printf("-1------",j);
    for(k=0;k<=l;k++)printf("%2d ",k);
    printf("\n");
    for(j=0;j<=l;j++)
    {
        printf("%2d------",j);
        for(k=0;k<=l;k++)printf("%2d ",jump[j][k]);
        printf("\n");
    }
    for(i=0;i<=l;i++)data[i]=99;
    data[0]=0;
    for(j=0;j<=l;j++)if(jump[0][j]>=1)data[j]=min(data[j],data[0]+jump[0][j]-1);
    for(i=1;i<=l;i++)
    {
        data[i]=min(data[i],data[i-1]+1);
        for(j=i;j<=l;j++)if(jump[i][j]>=1)data[j]=min(data[j],data[i]+jump[i][j]-1);
    }


    printf("30------ ");
    for(j=0;j<=l;j++)printf("%d ",data[j]);
    printf("\n");
    printf("%d\n",data[l]);
    return 0;
}

int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}

int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}

int search(int start,int now,int sign,int len)
{
    if(sign==len)
    {
        jump[start][now]=now-start-len+1;
        printf("%d %d= %d\n",start,now,jump[start][now]);
        return 0;
    }
    int i;
    for(i=now;i<l;i++)
    {
        if(s[i]==temp[sign])
        {
        search(start,i+1,sign+1,len);
        break;
        }
    }
}
