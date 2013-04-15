#include<stdio.h>
int main()
{
    int a,b,n,i,j,temp;
    scanf("%d%d%d",&a,&b,&n);
    for(i=-1000;i<=1000;i++)
    {
        temp=a;
        for(j=1;j<=n&&temp<=1000&&temp>=-1000;j++)
        {
            temp*=i;
        }
        if(temp==b)
        {
            if(n%2==0&&i<0)printf("%d",i*-1);
            else printf("%d",i);
            return 0;
        }
    }
    printf("No solution");
    return 0;
}
