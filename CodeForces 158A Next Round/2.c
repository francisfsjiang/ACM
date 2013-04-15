#include<stdio.h>
int main()
{
    int n,k,i,xx;
    int data[120];
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)scanf("%d",&data[i]);
        xx=k;
        if(data[k]>0)
        {
            for(i=k+1;i<=n;i++)
            {
                if(data[i]<data[k])break;
                xx++;
            }
        }
        else
        {
            xx--;
            for(i=k-1;i>=1;i--)
            {
                if(data[i]>0) break;
                xx--;
            }
        }
        printf("%d\n",xx);
    return 0;
}
