#include<stdio.h>
#include<math.h>
#define pie 3.1415926
double r[10000]={0};
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,t,j,end=0;
    double x,y,len;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%lf%lf",&x,&y);
        len=sqrt(x*x+y*y);
        while(r[end]<len)
        {
            end++;
            r[end]=sqrt((double)end*100/pie);
        }
        //printf("%lf  %d\n",len,end);
        for(i=end;;i--)if(r[i]>len&&r[i-1]<len)break;
        printf("Property %d: This property will begin eroding in year %d.\n",j,i);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
