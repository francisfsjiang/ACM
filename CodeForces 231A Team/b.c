#include<stdio.h>
int main()
{
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    if(m%2==0)printf("%d",m/2*n);
    else if(n%2==0)printf("%d",n/2*m);
    else printf("%d",(n*m-1)/2);
    return 0;
}
