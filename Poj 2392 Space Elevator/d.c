#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[450000]={0};
int data[405][3];
int sum[450000];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int k,i,j,ans;
    int quicksort(int s,int t);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d%d",&data[i][0],&data[i][1],&data[i][2]);
    }
    quicksort(0,k-1);
    //for(i=0;i<k;i++)printf("%d %d %d\n",data[i][0],data[i][1],data[i][2]);
    dp[0]=1;
    ans=0;
    for(i=0;i<k;i++)
   {
       memset(sum,0,sizeof(sum));
       for(j=data[i][0];j<=data[i][1];j++)
       {
           if(!dp[j]&&dp[j-data[i][0]]&&sum[j-data[i][0]]<data[i][2])
           {
               dp[j]=1;
               sum[j]=sum[j-data[i][0]]+1;
               if(ans<j)ans=j;
           }
       }
   }
   printf("%d",ans);
    return 0;
}

int quicksort(int s,int t)
{
     int i,j,y,temp,m;
     m=rand()%(t-s+1)+s;
     temp=data[m][1];
     data[m][1]=data[s][1];
     data[s][1]=temp;
     temp=data[m][0];
     data[m][0]=data[s][0];
     data[s][0]=temp;
     temp=data[m][2];
     data[m][2]=data[s][2];
     data[s][2]=temp;
     i=s;
     j=t+1;
     y=data[s][1];
     for(;i<j;)
     {
                 for(i++;data[i][1]<y;i++);
                 for(j--;data[j][1]>y;j--);
                 if(i<j)
                 {
                        temp=data[i][1];
                        data[i][1]=data[j][1];
                        data[j][1]=temp;
                        temp=data[i][0];
                        data[i][0]=data[j][0];
                        data[j][0]=temp;
                        temp=data[i][2];
                        data[i][2]=data[j][2];
                        data[j][2]=temp;
                 }
     }
     data[s][1]=data[j][1];
     data[j][1]=y;
     temp=data[s][0];
     data[s][0]=data[j][0];
     data[j][0]=temp;
     temp=data[s][2];
     data[s][2]=data[j][2];
     data[j][2]=temp;
     if(s<j-1)quicksort(s,j-1);
     if(j+1<t)quicksort(j+1,t);
}
