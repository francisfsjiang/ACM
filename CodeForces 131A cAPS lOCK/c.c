#include<stdio.h>
#include<string.h>
int main()
{
    int l,i,sign=1;
    char s[105];
    scanf("%s",s);
    l=strlen(s);
    for(i=1;i<l;i++)
    {
        if(s[i]>='a')
        {
            sign=0;
            break;
        }
    }
    if(sign==1)
    {
        for(i=0;i<l;i++)
        {
            if(s[i]<'a')s[i]+=32;
            else s[i]-=32;
        }
    }
    printf("%s",s);
    return 0;
}
