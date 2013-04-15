#include<stdio.h>
int main()
{
    int k,n,sum;
    int aa(int x,int k);
    scanf("%d%d",&k,&n);
    if(aa(n,k)==1)
    {
        printf("YES\n");
        sum=0;
        for(;n>=1;)
        {
            sum++;
            n/=k;
        }
        printf("%d",sum-2);
    }
    else printf("NO");
    return 0;
}

int aa(int x,int k)
{
    if(x<k)return 0;
    else if(x==k)return 1;
    else if(x%k==0)return aa(x/k,k);
    else return 0;
}
