#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,n,s,sum;
    int data[20500];
    void quicksort(int date[],int s,int t);
    while(scanf("%d%d",&n,&s)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&data[i]);
        }
        quicksort(data,0,n-1);
        /*for(i=0;i<n;i++)printf("%d ",data[i]);
        printf("\n");*/
        sum=0;
        for(i=0;i<n;i++)
        {
            if(0<s)
            {
                sum++;
                s-=data[i];
            }
            else break;
        }
        printf("%d\n",sum);
    }
    return 0;
}

void quicksort(int date[],int s,int t)
{
     int i,j,y,temp,m;
     i=s;
     j=t+1;
     y=date[s];
     for(;i<j;)
     {
                 for(i++;date[i]>y;i++);
                 for(j--;date[j]<y;j--);
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
