#include<stdio.h>
#include<string.h>
char s1[1000005],s2[10005];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,next[10005],l1,l2,k,t,sign;
    scanf("%d",&t);
while(t--)
{
    scanf("%s",s2);
    scanf("%s",s1);
    //printf("%s\n",s1);
    //printf("%s\n",s2);
    l1=strlen(s1);
    l2=strlen(s2);
    sign=0;
    next[1]=0;
    k=0;
    for(i=2;i<=l2;i++)
    {
        for(;k>0&&s2[k]!=s2[i-1];k=next[k]);
        if(s2[k]==s2[i-1])k++;
        next[i]=k;
    }
    /*for(i=1;i<=l2;i++)printf("%d ",next[i]);
    printf("\n");*/
    k=0;
    for(i=0;i<l1;i++)
    {
        for(;k>0&&s1[i]!=s2[k];k=next[k]);
        if(s1[i]==s2[k])k++;
        if(k==l2)
        {
            //printf("----%d  %d\n",i,k);
            sign++;
            k=next[k];
        }
    }
    printf("%d\n",sign);
}
    return 0;
}

int kmp(char s1[],char s2[],int start)
{
    int p[30],i,j,k,l2,l1;
    l1=strlen(s1);
    l2=strlen(s2);
    p[1]=0;
    k=0;
    for(i=2;i<=l2;i++)
    {
        for(;k>0&&s2[i-1]!=s2[k];k=p[k]);
        if(s2[i-1]==s2[k])k++;
        p[i]=k;
    }
    k=0;
    for(i=start;i<l2;i++)
    {
        for(;k>0&&s1[i]!=s2[k];k=p[k]);
        if(s1[i]==s2[k])k++;
        if(k==l2)
        {
            return i+1;
        }
    }
    return 0;
}
