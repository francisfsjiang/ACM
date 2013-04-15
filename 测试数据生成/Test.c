#include<stdio.h>
int main()
{
    freopen("out.out","w",stdout);
    int n=250,i,j;
    printf("%d %d\n",n,n);
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)printf("%d ",rand()%1000);
        printf("\n");
    }
    return 0;
}
