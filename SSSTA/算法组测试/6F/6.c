#include<stdio.h>
int data[1000005];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,i,j,k,x,m,n,max,sum,maxx,temp;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
                    for(i=0;i<=100000;i++)data[i]=0;
                    scanf("%d%d",&n,&m);
                    max=0;
                    for(i=0;i<n;i++)
                    {
                                    scanf("%d",&x);
                                    data[x]++;
                                    if(x>max)max=x;
                    }
    }
    return 0;
}
