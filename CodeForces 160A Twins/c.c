#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,data[1000],sum,temp,i,re;
    int quicksort(int date[],int s,int t);
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
        sum+=data[i];
    }
    quicksort(data,1,n);
    temp=0;
    re=0;
    for(i=n;i>=1;i--)
    {
        temp+=data[i];
        sum-=data[i];
        re++;

        if(temp>sum)break;
    }
    printf("%d",re);
    return 0;
}

int quicksort(int date[],int s,int t)
{
     int i,j,y,temp,m;
     i=s;
     j=t+1;
     y=date[s];
     for(;i<j;)
     {
                 for(i++;date[i]<y;i++);
                 for(j--;date[j]>y;j--);
                 if(i<j)
                 {
                        temp=date[i];
                        date[i]=date[j];
                        date[j]=temp;
                 }
     }
     date[s]=date[j];
     date[j]=y;
     if(s<j-1)quicksort(date,s,j-1);
     if(j+1<t)quicksort(date,j+1,t);
}
