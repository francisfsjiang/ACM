#include<stdio.h>
int main()
{
    int data[2],n,temp,sign;
    int gcd(int x,int y);
    scanf("%d%d%d",&data[0],&data[1],&n);
    sign=0;
    for(;;)
    {
        //printf("%d %d %d          %d\n",data[0],data[1],n,sign);
        if(n==0)break;
        temp=gcd(data[sign],n);
        //printf("%d\n",temp);
        n-=temp;
        if(n<0)break;
        if(sign==0)sign++;
        else sign=0;
    }
    if(sign==1)printf("0");
    else printf("1");
    return 0;
}

int gcd(int x,int y)
{
    if(x<y)
    {
        int temp=x;
        x=y;
        y=temp;
    }
    if(x%y==0)return y;
    else return gcd(y,x-y);
}
