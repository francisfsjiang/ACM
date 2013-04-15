#include<stdio.h>
struct matrix
{
    int a,b,c,d;
};

struct matrix mulitiply(struct matrix x,struct matrix y)
{
    struct matrix s;
    s.a=(x.a*y.a+x.b*y.c)%10000;
    s.b=(x.a*y.b+x.b*y.d)%10000;
    s.c=(x.c*y.a+x.d*y.c)%10000;
    s.d=(x.c*y.b+x.d*y.d)%10000;
    return s;
}

int main()
{
    int n;
    struct matrix ans,m;
while(1)
{
    scanf("%d",&n);
    if(n==-1)break;
    ans.a=1;
    ans.b=1;
    ans.c=1;
    ans.d=0;
    m.a=1;
    m.b=1;
    m.c=1;
    m.d=0;
    if(n==0)printf("0\n");
    else if(n==1)printf("1\n");
    else
    {
        n--;
        while(n)
        {
            if(n&1)ans=mulitiply(ans,m);
            n>>=1;
            m=mulitiply(m,m);
        }
        printf("%d\n",ans.b);
    }
}
    return 0;
}
