#include<stdio.h>
int data[105][10005];
int m,n;
char s[10005];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int searchb(int i,int j,int d);
    int searcha(int i,int j,int d);
    int i,j,sum,sign,temp;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        sign=0;
        scanf("%s",s);
        for(j=0;j<m;j++)sign+=s[j]-48;
        if(sign==0)
        {
            printf("-1");
            return 0;
        }
        if(sign==m)
        {
            for(j=0;j<m;j++)data[i][j]=0;
            continue;
        }
        else
        {
            for(j=0;j<m;j++)data[i][j]=10005;
        }
        for(j=0;j<m;j++)if(s[j]=='1')
        {
            //if(j==)
            searchb(i,j,0);
            searcha(i,j,0);
        }
        /*for(j=0;j<m;j++)printf("%d ",data[i][j]);
        printf("\n");*/
    }
    sum=1000000;
    for(j=0;j<m;j++)
    {
        temp=0;
        for(i=1;i<=n;i++)temp+=data[i][j];
        if(temp<sum)sum=temp;
    }
    printf("%d",sum);
    return 0;
}

int searchb(int i,int j,int d)
{
    //printf("searchb(%d,%d,%d)   data[%d][%d]=%d\n",i,j,d,i,j,data[i][j]);
    if(data[i][j]>=d)
    {
        data[i][j]=d;
        if(j-1<0&&s[m-1]!='1')searchb(i,m-1,d+1);
        else if(s[j-1]!='1')searchb(i,j-1,d+1);
    }
    else return 0;
}

int searcha(int i,int j,int d)
{
    //printf("searcha(%d,%d,%d)   data[%d][%d]=%d\n",i,j,d,i,j,data[i][j]);
    if(data[i][j]>=d)
    {
        data[i][j]=d;
        if(j+1>m-1&&s[0]!='1')searcha(i,0,d+1);
        else if (s[j+1]!='1') searcha(i,j+1,d+1);
    }
    else return 0;
}
