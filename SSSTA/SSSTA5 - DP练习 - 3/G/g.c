#include<stdio.h>
#include<math.h>
int data[10005];
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int min(int x,int y);
    int i,j,n;
    double s;
    data[0]=0;
    data[1]=1;
    for(i=2;i<=10000;i++)
    {
        data[i]=data[i-1]+1;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                data[i]=min(data[i],data[j]+data[i/j]);
            }
        }
    }
    //for(i=0;i<=10000;i++)printf("%d,",data[i]);
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",data[n]);
    }
    return 0;
}

int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}
