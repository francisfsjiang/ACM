#include<stdio.h>
int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};//n的阶乘
int main()
{
    int cantor(int x,int n);
    int cantorback(int x,int n);
    int n,temp,i;
    scanf("%d%d",&n,&temp);
    printf("%d\n",cantor(temp,n));
    printf("%d\n",cantorback(cantor(temp,n),n));
    return 0;
}

int cantor(int x,int n)//康托展开
{
    int num[20],i,j,temp;
    for(i=n;i>=1;i--)
    {
        num[i]=x%10;
        x=(x-x%10)/10;
    }
    int sum=0;
    for(i=1;i<=n;i++)
    {
        temp=0;
        for(j=i+1;j<=n;j++)if(num[j]<num[i])temp++;
        sum+=temp*fact[n-i];
    }
    return sum;
}

int cantorback(int x,int n)//康托展开的逆运算
{
    int i,j,num[20],sign[20]={0},temp,sum;
    for(i=1;i<=n;i++)
    {
        sum=(x-x%fact[n-i])/fact[n-i];
        temp=0;
        for(j=1;j<=n;j++)
        {
            if(sign[j]==0)
            {
                temp++;
                if(temp==sum+1)break;
            }
        }
        sign[j]=1;
        num[i]=j;
        x=x%fact[n-i];
    }
    temp=1;
    sum=0;
    for(i=n;i>=1;i--)
    {
        sum+=temp*num[i];
        temp*=10;
    }
    return sum;
}
