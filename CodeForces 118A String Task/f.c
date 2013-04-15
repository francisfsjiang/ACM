#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int l,i,n,sign;
    char s[1000];
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]<='Z'&&s[i]>='A')
        {
            s[i]+=32;
        }
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')continue;
        else
        {
            printf(".%c",s[i]);
        }
    }
    return 0;
}
