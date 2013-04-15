#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,t;
    int maxn,max,temp;
    int data[27];
    int l1,l2;
    char s1[50],s2[50],ss[50];
    scanf("%d",&t);
    for(;t>0;t--)
    {
        for(i=0;i<26;i++)data[i]=100;
        for(i=1;i<=3;i++)
        {
            scanf("%s%s%s",s1,s2,ss);
            l1=strlen(s1);
            l2=strlen(s2);
            if(ss[0]=='u')
            {
                for(j=0;j<l1;j++)data[s1[j]-65]--;
                for(j=0;j<l2;j++)data[s2[j]-65]++;
            }
            else if(ss[0]=='d')
            {
                for(j=0;j<l1;j++)data[s1[j]-65]++;
                for(j=0;j<l2;j++)data[s2[j]-65]--;
            }
            else
            {
                for(j=0;j<l1;j++)data[s1[j]-65]=-100;
                for(j=0;j<l2;j++)data[s2[j]-65]=-100;
            }
        }
        max=0;
        for(i=0;i<26;i++)
        {
            if(data[i]>100)temp=data[i]-100;
            else temp=100-data[i];
            if(data[i]>0&&temp>max)
            {
                max=temp;
                maxn=i;
            }
        }
        if(data[maxn]>100)printf("%c is the counterfeit coin and it is light. \n",maxn+65);
        else printf("%c is the counterfeit coin and it is heavy. \n",maxn+65);
    }
    return 0;
}
