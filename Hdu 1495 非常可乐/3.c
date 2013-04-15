#include<stdio.h>
#include<string.h>
int data[100][100][100];
int aa,mm,nn,sum=0;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int search(int a,int m,int n,int step);
    int i,j,k;
    while(1)
    {
        scanf("%d%d%d",&aa,&mm,&nn);
        if(aa==0)break;
        if(aa%2==1)
        {
            printf("NO\n");
            continue;
        }
        sum=9999999;
        memset(data,0,sizeof(data));
        //for(i=0;i<=101;i++)for(j=0;j<=101;j++)for(k=0;k<=101;k++)data[i][j][k]==0;
        search(aa,0,0,0);
        if(sum==9999999)printf("NO\n");
        else printf("%d\n",sum);
    }
    return 0;
}

int search(int a,int m,int n,int step)
{
    //printf("%d %d %d %d\n",a,m,n,step);
    if(((a==m&&a+m==aa)||(a==n&&a+n==aa)||(m==n&&n+m==aa))&&step<sum)
    {
        sum=step;
        //printf("----------%d %d %d %d\n",a,m,n,step);
    }
    if(data[a][m][n]!=0&&data[a][m][n]<=step)
    {
        return 0;
    }
    else
    {
        data[a][m][n]=step;
        if(a>0)
        {
            if(a>mm-m)search(a-mm+m,mm,n,step+1);
            else search(0,m+a,n,step+1);
            if(a>nn-n)search(a-nn+n,m,nn,step+1);
            else search(0,m,n+a,step+1);
        }
        if(m>0)
        {
            search(a+m,0,n,step+1);
            if(m>nn-n)search(a,m-nn+n,nn,step+1);
            else search(a,0,n+m,step+1);
        }
        if(n>0)
        {
            search(a+n,m,0,step+1);
            if(n>mm-m)search(a,mm,n-mm+m,step+1);
            else search(a,m+n,0,step+1);
        }
    }
    return 0;
}
