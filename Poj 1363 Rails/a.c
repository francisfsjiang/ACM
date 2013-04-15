#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int data[1005];
    int zhan[1005];
    int n,i,j,tail,in,x,scan;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        while(1)
        {
            memset(zhan,0,sizeof(zhan));
            scanf("%d",&x);
            //printf("out %d\n",x);
            if(x==0)break;
            in=1;
            tail=0;
            scan=1;
            for(;;)
            {
                if(zhan[tail]==x)
                {
                    tail--;
                    if(scan==n)break;
                    scanf("%d",&x);
                    //printf("out %d\n",x);
                    scan++;
                }
                else
                {
                    tail++;
                    //printf("in %d\n",in);
                    zhan[tail]=in;
                    in++;
                    if(in==n+2)break;
                }
            }
            if(scan==n)printf("Yes\n");
            else
            {
                for(i=scan;i<n;i++)
                {
                    scanf("%d",&x);
                }
                printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}
