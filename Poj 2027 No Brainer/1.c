#include<stdio.h>
int main()
{
    int x,y,i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        if(x<y)printf("NO BRAINS\n");
        else printf("MMM BRAINS\n");
    }
    return 0;
}
