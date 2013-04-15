#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,i,j,x,n,numright,numleft,pos,sign,sum;
    int data[100000];
    scanf("%d",&t);
    for(;t>0;t--)
    {
        scanf("%d",&n);
        numleft=0;
        pos=0;
        //numright=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(;numleft<x;)
            {
                data[pos]=0;
                numleft++;
                pos++;
            }
            data[pos]=1;
            pos++;
        }
        /*for(i=0;i<pos;i++)printf("%d ",data[i]);
        printf("\n");*/
        for(i=0;i<pos;i++)
        {
            if(data[i]==0)continue;
            //printf("%d\n",i);
            sign=1;
            sum=0;
            for(j=i-1;;j--)
            {
                if(sign==0)break;
                if(data[j]==1)sign++;
                else if(data[j]==0){sign--;sum++;}
            }
            printf("%d ",sum);
        }
        printf("\n");
    }
    return 0;
}
