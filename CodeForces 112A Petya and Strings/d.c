#include<stdio.h>
#include<string.h>
int main()
{
    int l,i;
    char s1[10005],s2[10005];
    scanf("%s%s",s1,s2);
    l=strlen(s1);
    for(i=0;i<l;i++)
    {
        if(s1[i]<'a')s1[i]+=32;
        if(s2[i]<'a')s2[i]+=32;
        if(s1[i]>s2[i])
        {
            printf("1");
            break;
        }
        else if(s1[i]<s2[i])
        {
            printf("-1");
            break;
        }
    }
    if(i==l)printf("0");
    return 0;
}
