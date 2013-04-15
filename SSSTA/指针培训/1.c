#include<stdio.h>
int main()
{
    int a;
    int *x;
    void addone(int *p);
    scanf("%d",&a);
    x=&a;
    addone(x);
    printf("%d",a);
    return 0;
}

void addone(int *p)
{
    *p=*p+1;
}
