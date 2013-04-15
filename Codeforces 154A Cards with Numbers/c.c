#include<stdio.h>
#include<stdlib.h>
int data[600010][2];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,n,sum,mid,sign;
    int sq(int s,int t);
    scanf("%d",&n);
    if(n==1)
    {
        printf("-1\n");
        return 0;
    }
    mid=n;
    n=n*2;
    sum=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i][0]);
        data[i][1]=i;
        sum+=data[i][0];
    }
    /*for(i=1;i<=n;i++)printf("%d ",data[i][0]);
    printf("\n");*/
    sq(1,n);
    /*for(i=1;i<=n;i++)printf("%d ",data[i][0]);
    printf("\n");*/
    sum=sum*2/n;
    sign=0;
    for(i=1;i<=mid;i++)
    {
        if(data[i][0]+data[n-i+1][0]!=sum)sign=1;
    }
    if(sign==1)
    {
        printf("-1\n");
    }
    else
    {
        for(i=1;i<=mid;i++)printf("%d %d\n",data[i][1],data[n-i+1][1]);
    }
    return 0;
}

int sq(int s,int t)
{
    int i,j,m,y,temp;
    m=rand()%(t-s+1)+s;
    temp=data[m][0];
    data[m][0]=data[s][0];
    data[s][0]=temp;
    temp=data[m][1];
    data[m][1]=data[s][1];
    data[s][1]=temp;
    y=data[s][0];
    i=s;
    j=t+1;
    for(;i<j;)
    {
        for(i++;data[i][0]<y;i++);
        for(j--;data[j][0]>y;j--);
        if(i<j)
        {
            temp=data[i][1];
            data[i][1]=data[j][1];
            data[j][1]=temp;
            temp=data[i][0];
            data[i][0]=data[j][0];
            data[j][0]=temp;
        }
    }
    data[s][0]=data[j][0];
    data[j][0]=y;
    temp=data[s][1];
    data[s][1]=data[j][1];
    data[j][1]=temp;
    if(s<j-1)sq(s,j-1);
    if(t>j+1)sq(j+1,t);
}
