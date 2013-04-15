#include<stdio.h>
int data[1005][2];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int quicksort(int s,int t);
    int i,j,n,s;
    scanf("%d%d",&s,&n);
    for(i=1;i<=n;i++)scanf("%d%d",&data[i][0],&data[i][1]);
    quicksort(1,n);
    for(i=1;i<=n;i++)
    {
        if(data[i][0]<s)
        {
            s+=data[i][1];
        }
        else
        {
            printf("NO");
            break;
        }
    }
    if(i>n)printf("YES");
return 0;
}

int quicksort(int s,int t)
{
     int i,j,y,temp,m;
     i=s;
     j=t+1;
     y=data[s][0];
     for(;i<j;)
     {
                 for(i++;data[i][0]<y;i++);
                 for(j--;data[j][0]>y;j--);
                 if(i<j)
                 {
                        temp=data[i][0];
                        data[i][0]=data[j][0];
                        data[j][0]=temp;
                        temp=data[i][1];
                        data[i][1]=data[j][1];
                        data[j][1]=temp;
                 }
     }
     data[s][0]=data[j][0];
     data[j][0]=y;
     temp=data[s][1];
     data[s][1]=data[j][1];
     data[j][1]=temp;
     if(s<j-1)quicksort(s,j-1);
     if(j+1<t)quicksort(j+1,t);
}
