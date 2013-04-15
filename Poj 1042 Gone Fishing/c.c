#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,h,i,j,temph,sum,max,maxn;
    int result[27],resultfish=0,resultn=0;
    int data[27],fish[27],dec[27],time[27],way[27]={0};
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        scanf("%d",&h);
        resultfish=0;
        memset(time,0,sizeof(time));
        memset(result,0,sizeof(result));
        memset(data,0,sizeof(data));
        memset(dec,0,sizeof(dec));
        memset(way,0,sizeof(way));
        h=h*12;
        for(i=1;i<=n;i++)scanf("%d",&data[i]);
        for(i=1;i<=n;i++)scanf("%d",&dec[i]);
        for(i=1;i<=n-1;i++)scanf("%d",&way[i]);
        /*for(j=1;j<=n;j++)printf("%d ",data[j]);
        printf("\n");*/
        for(i=1;i<=n;i++)
        {
            sum=0;
            temph=h;
            for(j=i-1;j>=1;j--)temph-=way[j];
            for(j=1;j<=i;j++)fish[j]=data[j];
            /*printf("%d\n",temph);
            for(j=1;j<=i;j++)printf("%d ",fish[j]);
            printf("\n");*/
            memset(time,0,sizeof(time));
            while(temph>0)
            {
                max=0;
                maxn=0;
                for(j=1;j<=i;j++)
                {
                    if(fish[j]>max)
                    {
                        max=fish[j];
                        maxn=j;
                    }
                }
                //printf("%d---***--\n",max);
                if(max==0)
                {
                    /*for(j=1;j<=n;j++)printf("%d ",time[j]);
            printf("\n");
                    printf("%d--------\n",temph);*/
                     time[1]+=temph;
                    break;
                }
                sum+=fish[maxn];
                time[maxn]++;
                fish[maxn]-=dec[maxn];
                temph--;
                //printf("****%d\n",sum);
            }
            /*for(j=1;j<=n;j++)printf("%d ",time[j]);
            printf("\n");*/
            if(sum>resultfish)
            {
                for(j=1;j<=i;j++)result[j]=time[j];
                resultfish=sum;
                resultn=i;
            }
            //printf("----%d\n----------------------\n",resultfish);
        }
        if(resultfish==0)result[1]=h;
        for(i=1;i<=n;i++)
        {
            if(i!=1)printf(", ");
            printf("%d",result[i]*5);
        }
        printf("\nNumber of fish expected: %d\n\n",resultfish);
    }
    return 0;
}
