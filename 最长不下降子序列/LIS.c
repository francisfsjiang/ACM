#include<stdio.h>
#include<string.h>
#define max 1000
int a[max],k;
void find(int x,int y,int b)
{
    int mid;
    int f;
    while(x<y)
    {
        mid=(x+y)/2;
        if(a[mid]>=b)
        {
            f=mid;
            y=mid;
        }
        else x=mid+1;
    }
    if(a[x]>=b) f=x;
    a[f]=b;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,n,b;
    while(scanf("%d",&n)!=-1)
    {
        memset(a,0,sizeof(a));
        k=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b);
            if(b>a[k])a[++k]=b;
            else find(1,k,b);
        }
        printf("%d\n",k);
    }
    return 0;
}
