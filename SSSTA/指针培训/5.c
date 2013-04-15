#include<stdio.h>
int main()
{
    void process(int x,int y,int (*p)(int,int));
    int sum(int x,int y);
    int minus(int x,int y);
    int x(int x,int y);
    int max(int x,int y);
    int a,b;
    int *p;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
            process(a,b,minus);
            process(a,b,x);
            process(a,b,sum);
            process(a,b,max);
    }
    return 0;
}

void process(int x,int y,int (*p)(int,int))
{
    p(x,y);
}

int sum(int x,int y)
{
    printf("%d\n",x+y);
}

int minus(int x,int y)
{
    printf("%d\n",x-y);
}

int x(int x,int y)
{
    printf("%d\n",x*y);
}

int max(int x,int y)
{
    if(x>y)printf("%d\n",x);
    else printf("%d\n",y);
}
