#include<stdio.h>
#include<time.h>
#define m 0
#define n 2147483640
int main()
{
    int i,j;
    double s;
    s=time(NULL);
    printf("%lf",s);
    s=localtime(NULL);
    printf("%lf",s);
    //for(i=m;i<=n;++i);
    return 0;
}
