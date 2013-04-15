#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,l,sum,i;
    char s[1000];
    while(scanf("%s",s)!=EOF)
    {
    l=strlen(s);
    sum=0;
    for(i=0;i<l;i++)
    {
        if(sum<0&&i!=0)
        {
            break;
        }
        if(s[i]=='(')sum++;
        else if(s[i]==')')sum--;
    }
    if(i==l)
    {
    if(sum==0)printf("YES\n");
    else printf("NO\n");
    }
    else printf("NO\n");
    }
return 0;
}
