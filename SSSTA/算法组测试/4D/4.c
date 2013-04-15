#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int x,y,z,t,k,i,j,sumer,temp,a,b;
    int data[15];
    int sum[15];
    int XXOO(int x,int y,int z);
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
                    for(i=1;i<=13;i++)sum[i]=0;
                   sumer=0;
                   temp=0;
                   scanf("%d%d",&a,&b);
                   sum[a]++;
                   sum[b]++;
                   scanf("%d%d%d",&x,&y,&z);
                   sum[x]++;
                   sum[y]++;
                   sum[z]++;
                   temp=XXOO(x,y,z);
                   if(temp>sumer)sumer=temp;
                   
                   
                   scanf("%d%d%d",&x,&y,&z);
                   sum[x]++;
                   sum[y]++;
                   sum[z]++;
                   temp=XXOO(x,y,z);
                   if(temp>sumer)sumer=temp;
                   
                   temp=0;
                   for(j=1;j<=13;j++)
                   {
                                     if(sum[j]>=4)continue;
                                     temp=XXOO(a,b,j);
                                     if(temp>sumer)
                                     {
                                                 printf("%d\n",j);
                                                 break;
                                     }
                   }
                   if(j==14)printf("Impossible\n");
    
    /*x=rand()%13+1;
    y=rand()%13+1;
    z=rand()%13+1;
    printf("%d %d %d       %d\n",x,y,z,XXOO(x,y,z));*/
    }
    
    return 0;
}

int XXOO(int x,int y,int z)
{
    int data[15],i;
    for(i=1;i<=13;i++)data[i]=0;
    data[x]++;
                   data[y]++;
                   data[z]++;
                   return x*data[x]+y*data[y]+z*data[z];
}
