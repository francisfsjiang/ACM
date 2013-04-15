#include<stdio.h>
int main()
{
    int a,b;
    void swap(int *x,int *y);
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("%d %d",a,b);
    return 0;
}

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
