#include<stdio.h>
#include<stdlib.h>
int main()
{
    freopen("in.in","w",stdout);
    int i,n,m;
    for(i=0;i<=1212;i++)
    {
        m=rand()%100+1;
        n=rand()%100+1;
        if(m<n)
        {
            continue;
            i--;
        }
        printf("%d %d %d\n",m,n,m-n);
    }
    printf("0 0 0");
    return 0;
}
