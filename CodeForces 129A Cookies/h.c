#include<stdio.h>
int main()
{
    int n,x,i,s1=0,s2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x%2==0)s2++;
        else s1++;
    }
    if(s1%2==0)printf("%d",s2);
    else printf("%d",s1);
    return 0;
}
