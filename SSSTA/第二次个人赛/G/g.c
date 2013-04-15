#include<stdio.h>
#include<string.h>
int data[2000];
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,m,t,i,first;
    int cars[1440],time[1440],trips[1440];
    int cases;
    scanf("%d",&cases);
    while (cases--)
    {
        scanf("%d%d%d",&n,&t,&m);
        for (i=1;i<=m;++i)scanf("%d",&cars[i]);
        first=m % n;
        if(first)
        {
            i=first;
            time[i]=cars[i]+t;
            trips[i]=1;
        }
        else
        {
            i=0;
            time[0]=-t;
            trips[0]=0;
        }
        for(i+=n;i<=m;i+=n)
        {
            time[i]=max(time[i-n]+t,cars[i])+t;
            trips[i]=trips[i-n]+1;
        }
        printf("%d %d\n",time[m],trips[m]);
    }
    return 0;
}
