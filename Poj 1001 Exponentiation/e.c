#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k;
    char s[20];
    int data[51];
    int data2[51];
    int num[10],numm,temp,sum;
    int n,sign;
    for(;scanf("%s",s)!=EOF;)
    {
        printf("\n---------------------\n");\
        for(i=0;i<=50;i++)data[i]=0;
        for(i=0;i<=50;i++)data2[i]=0;
        scanf("%d",&n);
        numm=0;
        for(i=0;s[i]>=48&&s[i]<=57;i++)
        {
            num[numm]=s[i]-48;
            numm++;
        }
        sign=5-numm;
        printf("%s\nsign=%d\n",s,sign);
        for(i++;s[i]>=48&&s[i]<=57;i++)
        {
            num[numm]=s[i]-48;
            numm++;
        }
        for(i=0;i<5;i++)printf("%d  ",num[i]);
        printf("\n");
        data[0]=1;
        for(i=0;i<=1;i++)
        {
            temp=num[i];
            num[i]=num[4-i];
            num[4-i]=temp;
        }
        for(i=0;i<5;i++)printf("%d  ",num[i]);
        printf("\n");
        data[1]=1;
        sum=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=5;j++)
            {
                for(k=j;k<=j+sum-1;k++)data2[k]+=data[k]*num[j];
            }
        }
    }
    return 0;
}
