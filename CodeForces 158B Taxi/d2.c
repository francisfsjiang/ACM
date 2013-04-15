#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int min(int x,int y);
    int n,i,temp,sum,x;
    int data[5]={0};
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==4)sum++;
        else data[x]++;
    }
    if(data[3]>data[1])
    {
        sum+=data[3];
        sum+=(data[2]+1)/2;
    }
    else
    {
        sum+=data[3];
        data[1]-=data[3];
        if(data[1]/2>data[2])
        {
            sum+=data[2];
            data[1]-=data[2]*2;
            sum+=(data[1]+3)/4;
        }
        else
        {
            sum+=(data[1]+1)/2;
            data[2]-=(data[1]+1)/2;
            sum+=(data[2]+1)/2;
        }
    }
    printf("%d",sum);
    return 0;
}
