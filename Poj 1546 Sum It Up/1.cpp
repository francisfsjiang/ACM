#include<iostream>
#include<cstdio>
using namespace std;
int n,k,x;
bool f;
int h[100];
int a[100];
void find(int p,int m)
{
    int i;
    if (m>k) return;
    if (m==k)
    {
        f=false;
        printf("%d",h[1]);
        for (i=2; i<=x; i++) printf("+%d",h[i]);
        printf("\n");
        return;
    }
    for (i=p+1; i<=n; i++)
    {
        x++;
        h[x]=a[i];
        find(i,m+a[i]);
        x--;
        while((i<=n)&&(a[i]==a[i+1]))i++;
    }
}
int main()
{
    freopen("1.in","r",stdin);
    while(1)
    {
        scanf("%d%d",&k,&n);
        if(n==0&&k==0)break;
        else
        {
            printf("Sums of %d:\n",k);
            for(int i=1;i<=n;i++)scanf("%d",&a[i]);
            x=0;
            f=true;
            find(0,0);
            if(f)printf("NONE\n");
        }
    }
    return 0;
}
