#include<stdio.h>
int main()
{
    int n,a,b,temp;
    scanf("%d%d%d",&n,&a,&b);
    temp=n-a;
    b++;
    if(temp>b)printf("%d",b);
    else printf("%d",temp);
    return 0;
}
