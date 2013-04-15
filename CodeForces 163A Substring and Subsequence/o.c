#include<stdio.h>
#include<string.h>
int data[5005][26];
char s1[5005],s2[5005];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int search(int i,int j);
    int l1,l2,i,j,sign,temp;
    long long sum=0;
    scanf("%s%s",s1,s2);
    //printf("%s\n%s\n",s1,s2);
    l1=strlen(s1);
    l2=strlen(s2);
    for(i=1;i<=l2;i++)
    {
        if(data[0][s2[i-1]-97]==0)data[0][s2[i-1]-97]=i;
        for(j=i-1;j>=1&&data[j][s2[i-1]-97]==0;j--)data[j][s2[i-1]-97]=i;
    }
    /*for(i=0;i<26;i++)
    {
        printf("%c ",i+97);
        for(j=0;j<=l2;j++)printf("%2d ",data[j][i]);
        printf("\n");
    }*/
    for(i=0;i<l1;i++)
    {
        sign=data[0][s1[i]-97];
        for(;sign!=0;)
        {
            temp=search(sign,i);
            //printf("%d-----------%d\n",i,temp);
            sum+=temp;
            sign=data[sign][s1[i]-97];
        }
        sum=sum%1000000007;
    }
    printf("%I64d",sum);
    return 0;
}

int search(int i,int j)
{
        int sum=0,sign;
        sign=data[i][s1[j+1]-97];
        for(;sign!=0;)
        {
            sum+=search(sign,j+1);;
            sign=data[sign][s1[j+1]-97];
        }
        //printf("search(%d,%d)=%d\n",i,j,sum+1);
        return sum+1;
}
