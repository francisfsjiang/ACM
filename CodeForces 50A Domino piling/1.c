#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int sum,i,n,x,y,z,temp;
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        temp=x+y+z;
        if(temp>=2)sum++;
    }
    printf("%d",sum);
}
