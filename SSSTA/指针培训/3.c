#include<stdio.h>
int main()
{
    double x[3];
    float *p;
    int i;
    void rev(float *p,int x);
    while(scanf("%lf%lf%lf",&x[0],&x[1],&x[2])!=EOF)
    {
   // rev(x,3);
    printf("%lf %lf %lf\n",x[0],x[1],x[2]);
    }
    return 0;
}

void rev(float *p,int x)
{
    int i;
    float temp;
    x--;
    for(i=0;i<x;i++,x--)
    {
        temp=*(p+i);
        *(p+i)=*(p+x);
        *(p+x)=temp;
    }
}
