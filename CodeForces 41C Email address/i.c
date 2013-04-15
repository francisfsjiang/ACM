#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,l,i,sign;
    char s[1000];
    scanf("%s",s);
    l=strlen(s);
    printf("%c",s[0]);
    sign=0;
    for(i=1;i<l;i++)
    {
        if(i!=l-3&&s[i]=='d'&&s[i+1]=='o'&&s[i+2]=='t')
        {
            printf(".");
            i+=2;
        }
        else if(i!=l-2&&s[i]=='a'&&s[i+1]=='t'&&sign==0)
        {
            printf("@");
            i+=1;
            sign=1;
        }
        else printf("%c",s[i]);
    }
    return 0;
}
