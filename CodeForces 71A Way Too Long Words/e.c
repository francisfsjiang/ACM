#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    char s[1000];
    int n,l,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    scanf("%s",s);
     l=strlen(s);
    if(l>10)
    {
        printf("%c%d%c\n",s[0],l-2,s[l-1]);
    }
    else printf("%s\n",s);
    }
    return 0;
}
